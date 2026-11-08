/* @unit 0CB81860-0CB81C80 -speed +pool32 +poolafter=CEventSe_SetPitch,EventSe_Volume */
/* Event sound effects: one id per sound, each a task that eases its volume, pan and pitch toward a target. Sonic Adventure DC's own se.c, read
   from the code. The sound state lives in the task's work, from +16. */

typedef int Sint32;
typedef struct task task;

typedef struct {
    Sint32 id;
    Sint32 cur_volume, dst_volume, frm_volume;
    Sint32 cur_pan, dst_pan, frm_pan;
    Sint32 cur_pitch, dst_pitch, frm_pitch;
} CEventSeInfo;

typedef struct {
    char head[16];
    CEventSeInfo info;
} taskwk;

struct task {
    task *next, *last, *ptp, *ctp;
    void (*exec)(task *);
    void (*disp)(task *);
    void (*dest)(task *);
    void *ocp;
    taskwk *twp;
};

task *CreateElementalTask(int im, int level, void (*exec)(task *));
void FreeTask(task *tp);
void *CAlloc(Sint32 count, Sint32 size);
void Free(void *p);
void dsPlay_timer(Sint32 se, Sint32 id, Sint32 a, Sint32 b, Sint32 frame);
void dsStop_id(Sint32 id);
void dsVolume_id(Sint32 id, Sint32 volume);
void dsPan_id(Sint32 id, Sint32 pan);
void dsPitch_id(Sint32 id, Sint32 pitch);
Sint32 TH_GetWork(Sint32 n);

extern Sint32 gMaxId;
extern task **gCEventSePP;
extern Sint32 gOneshotId;

static void CEventSe_Dest(task *tp)
{
    CEventSeInfo *info = &tp->twp->info;

    dsStop_id(info->id);
}

static void CEventSe_Exec(task *tp)
{
    CEventSeInfo *info = &tp->twp->info;
    Sint32 id = info->id;

    if (info->frm_volume > 0) {
        Sint32 frm = info->frm_volume;
        Sint32 cur = info->cur_volume;
        Sint32 dst = info->dst_volume;
        Sint32 v = (dst + cur * (frm - 1)) / frm;

        dsVolume_id(id, v);
        info->cur_volume = v;
        info->frm_volume--;
    }
    if (info->frm_pan > 0) {
        Sint32 frm = info->frm_pan;
        Sint32 cur = info->cur_pan;
        Sint32 dst = info->dst_pan;
        Sint32 v = (dst + cur * (frm - 1)) / frm;

        dsPan_id(id, v);
        info->cur_pan = v;
        info->frm_pan--;
    }
    if (info->frm_pitch > 0) {
        Sint32 frm = info->frm_pitch;
        Sint32 cur = info->cur_pitch;
        Sint32 dst = info->dst_pitch;
        Sint32 v = (dst + cur * (frm - 1)) / frm;

        dsPitch_id(id, v);
        info->cur_pitch = v;
        info->frm_pitch--;
    }
}

static task *CEventSe_Create(Sint32 se, Sint32 frame)
{
    task *tp;
    Sint32 id;
    CEventSeInfo *info;

    tp = CreateElementalTask(2, 5, 0);
    if (tp) {
        id = (Sint32)tp;
        dsPlay_timer(se, id, 1, 0, frame);
        tp->exec = CEventSe_Exec;
        tp->dest = CEventSe_Dest;
        info = &tp->twp->info;
        info->id = id;
        info->cur_volume = 0;
        info->dst_volume = 0;
        info->frm_volume = 0;
        info->cur_pan = 0;
        info->dst_pan = 0;
        info->frm_pan = 0;
        info->cur_pitch = 0;
        info->dst_pitch = 0;
        info->frm_pitch = 0;
    }
    return tp;
}

static void CEventSe_SetVolume(task *tp, Sint32 volume, Sint32 frame)
{
    CEventSeInfo *info = &tp->twp->info;

    info->dst_volume = volume;
    info->frm_volume = frame;
    if (frame <= 0) {
        dsVolume_id(info->id, volume);
        info->cur_volume = volume;
    }
}

static void CEventSe_SetPan(task *tp, Sint32 pan, Sint32 frame)
{
    CEventSeInfo *info = &tp->twp->info;

    info->dst_pan = pan;
    info->frm_pan = frame;
    if (frame <= 0) {
        dsPan_id(info->id, pan);
        info->cur_pan = pan;
    }
}

static void CEventSe_SetPitch(task *tp, Sint32 pitch, Sint32 frame)
{
    CEventSeInfo *info = &tp->twp->info;

    info->dst_pitch = pitch;
    info->frm_pitch = frame;
    if (frame <= 0) {
        dsPitch_id(info->id, pitch);
        info->cur_pitch = pitch;
    }
}

void EventSe_Init(Sint32 maxid)
{
    if (!gCEventSePP) {
        gCEventSePP = (task **)CAlloc(maxid, 4);
        gMaxId = maxid;
    }
}

void EventSe_Close(void)
{
    Sint32 i;

    if (gCEventSePP) {
        for (i = 0; i < gMaxId; i++) {
            if (gCEventSePP[i])
                FreeTask(gCEventSePP[i]);
        }
        Free(gCEventSePP);
        gCEventSePP = 0;
    }
}

void EventSe_Play(Sint32 id, Sint32 se, Sint32 frame)
{
    if (id < gMaxId && !gCEventSePP[id])
        gCEventSePP[id] = CEventSe_Create(se, frame);
}

void EventSe_Stop(Sint32 id)
{
    if (id < gMaxId && gCEventSePP[id]) {
        FreeTask(gCEventSePP[id]);
        gCEventSePP[id] = 0;
    }
}

void EventSe_Volume(Sint32 id, Sint32 volume, Sint32 frame)
{
    if (id < gMaxId && gCEventSePP[id])
        CEventSe_SetVolume(gCEventSePP[id], volume, frame);
}

void EventSe_Pan(Sint32 id, Sint32 pan, Sint32 frame)
{
    if (id < gMaxId && gCEventSePP[id])
        CEventSe_SetPan(gCEventSePP[id], pan, frame);
}

void EventSe_Pitch(Sint32 id, Sint32 pitch, Sint32 frame)
{
    if (id < gMaxId && gCEventSePP[id])
        CEventSe_SetPitch(gCEventSePP[id], pitch, frame);
}

void EventSe_Oneshot(Sint32 se, Sint32 volume, Sint32 pan, Sint32 pitch)
{
    Sint32 id = TH_GetWork(0) + gOneshotId;

    dsPlay_timer(se, id, 1, 0, 120);
    dsVolume_id(id, volume);
    dsPan_id(id, pan);
    dsPitch_id(id, pitch);
    gOneshotId++;
    gOneshotId &= 0x1F;
}

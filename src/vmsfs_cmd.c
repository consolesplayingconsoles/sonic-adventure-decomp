/* @unit 8C647B90-8C647C54 */
/* VMS file system (vmsfs): the eight command slots and their setters. One source file of the SDK: its functions share one literal pool.
   The slot layout is read from the code: 128 bytes each, the state at +4, the function at +8, six parameters at +20, the volume name at +76,
   the callbacks at +116. Names from the SDK's function names; the C written for this game's bytes. */

struct VmsCmd {
    int w0;
    int state;
    void *func;
    int pad[2];
    int param[6];
    int pad2[8];
    char volume[32];
    int pad3[2];
    void *complete;
    void *progress;
    void *cbparam;
};

extern struct VmsCmd gVmsFileCommandStates[];

void vmsfs_c_setcompletecallback(void *f)
{
    int i;

    for (i = 0; i < 8; i++)
        gVmsFileCommandStates[i].complete = f;
}

void vmsfs_c_setprogresscallback(void *f)
{
    int i;

    for (i = 0; i < 8; i++)
        gVmsFileCommandStates[i].progress = f;
}

void vmsfs_c_setcallbackparam(void *p)
{
    int i;

    for (i = 0; i < 8; i++)
        gVmsFileCommandStates[i].cbparam = p;
}

int vmsfs_c_getstate(int i)
{
    struct VmsCmd *c = &gVmsFileCommandStates[i];

    return c->state;
}

void vmsfs_c_setfunc(int i, void *f)
{
    struct VmsCmd *c = &gVmsFileCommandStates[i];

    c->func = f;
}

void vmsfs_c_setparam(int i, int a, int b, int c2, int d, int e, int f)
{
    struct VmsCmd *c = &gVmsFileCommandStates[i];

    c->param[0] = a;
    c->param[1] = b;
    c->param[2] = c2;
    c->param[3] = d;
    c->param[4] = e;
    c->param[5] = f;
    c->state = 1;
}

void vmsfs_c_setvolume(int i, char *v)
{
    struct VmsCmd *c = &gVmsFileCommandStates[i];
    char *d = c->volume;

    do {
        *d++ = *v++;
    } while (d < c->volume + 32);
}

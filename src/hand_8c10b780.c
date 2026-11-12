/* @unit 8C10B780-8C10B8E0 +egflags +pool32 +onepool */
/* movie_play (Japanese release src/progress/movie.c) followed by an EU-only init function that shares its literal pool. */
typedef unsigned long Uint32;

extern void ADX_Close(void);
extern void njSetBorderColor(Uint32 color);
extern void njSetBackColor(Uint32 a, Uint32 b, Uint32 c);
extern void njWaitVSync(void);
extern void njSetVSyncFunction(void (*func)(void));
extern void loader_poll_drive(void);
extern void frame_vsync(void);
extern int thunk_FUN_8c09cbc0(char *name, void *dest);
extern char DATA_8c15ff9c[];
extern int movie_entry(int list);
extern void syCacheICI_P2_(void);
extern void cache_ram_restore(void);
extern void draw_model_init(void);
extern int movie_request;

int movie_play(int list)
{
    int result;
    ADX_Close();
    njSetBorderColor(0);
    njSetBackColor(0, 0, 0);
    njWaitVSync();
    njSetVSyncFunction(loader_poll_drive);
    thunk_FUN_8c09cbc0(DATA_8c15ff9c, ((void *)movie_entry));
    ((void (*)(void))(0xa0000000 | (Uint32)syCacheICI_P2_))();
    result = movie_entry(list);
    cache_ram_restore();
    draw_model_init();
    njSetVSyncFunction(frame_vsync);
    movie_request = 0;
    return result;
}

extern void FUN_8c608734(int);
extern void FUN_8c640692(void);
extern void FUN_8c604900(int, int, int);
extern void FUN_8c604d0e(int, int, int, int, int);
extern void njInitPrint(Uint32 *texture, Uint32 size, Uint32 attr);
extern void text_set_size(int);
extern void text_style_init(int, int, int);

void FUN_8c10b7e6(int mode)
{
    FUN_8c608734(mode);
    FUN_8c640692();
    if (mode == 0) {
        FUN_8c604900(*(int *)0x8c7a7f20, *(int *)0x8c7a7f24, *(int *)0x8c7a7f28);
        FUN_8c604d0e(-1, 0, 0x4e20, 0, 0);
    } else {
        FUN_8c604900(*(int *)0x8c7a7f2c, 0, 1);
        FUN_8c604d0e(-1, 0, 0x20000, 0, 0x8000);
    }
    njInitPrint(0, 0, 0);
    text_style_init(0, 0, 0);
    text_set_size(16);
}

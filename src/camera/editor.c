/* @unit 8C01C480-8C01DDE0 @data 8C111FAC-8C11211C +r04 +egflags +pool32 -noinline */
/* the debug editor of an act's camera collisions */
#include <ninja.h>
#include <sg_xpt.h>
#include <shinobi.h>
#include <stdio.h>

#include "camera/camera.h"
#include "camera/editor.h"
#include "collision/collision.h"
#include "debug/debug.h"
#include "debug/editor.h"
#include "draw/draw.h"
#include "draw/model.h"
#include "player/player.h"
#include "stage/stage.h"
#include "system/frame.h"
#include "system/pad.h"
#include "system/task.h"
#include "system/util.h"
void njCalculateLightsRGB(NJS_ARGB *color, NJS_POINT3 *point,
                          NJS_VECTOR *normal_jp, Int reverse);
void njCalculateLightsRGBVertex(NJS_ARGB *color, NJS_POINT3 *point,
                                NJS_VECTOR *normal_jp, Int reverse);
void njCalculateLightsRGBPacked(Uint32 *color, NJS_POINT3 *point,
                                NJS_VECTOR *normal_jp, Int reverse);
void njCalculateLightsRGBPackedVertex(Uint32 *color, NJS_POINT3 *point,
                                      NJS_VECTOR *normal_jp, Int reverse);
void FUN_8c6409c0(Int loc, Int val, Int digit);
void njUserClipping_jp(Int mode, NJS_POINT2 *p);
Bool late_DrawObjectClipEx(Uint32 n);
Float CalcDistance(NJS_POINT3 *p1, NJS_POINT3 *p2);
void late_DrawObjectClip(NJS_OBJECT *obj);
void njGetkmPointer_jp(void);
void njSetkmPointer_jp(void);
void njSetEORflag_jp();
void *njStartVertexNonTexOpaque_jp(void);
void *njStartVertexTexOpaque_jp(void);
void *njStartVertexNonTexTransIntens_jp(Uint32 *color);
void *njStartVertexTexOpaqueIntens_jp(Uint32 *color);
void njEndVertex_jp(Uint32 *vertex);
Sint32 njSetkmTextureNum_jp(Uint32 n);
void late_DrawSprite2D(NJS_SPRITE *sp, Int n, Float pri, Uint32 attr);
void CHAOS_SetChaosNo(Uint32 c);
void thunk_FUN_8c652d78(Uint32 density);
void ReleaseModule(NJS_FOG_TABLE fog, Float n, Float f);
void njSetVSyncFunction_jp(void (*func)(void));
void njWaitVSync_jp(void);
Uint32 njCalcTexture_jp(Uint32 flag);
Sint32 njSetTexture_jp(NJS_TEXLIST *texlist);
Sint32 njSetTextureNum_jp(Uint32 n);
Sint32 NeonuLoadTexture(NJS_TEXLIST *texlist);
Sint32 njReleaseTexture_jp(NJS_TEXLIST *texlist);
Sint32 njLoadTexturePvmFile_jp(const char *filename, NJS_TEXLIST *texlist);
Sint32 njLoadTexturePvmMemory_jp(Uint8 *addr, NJS_TEXLIST *texlist);
void njSetBackColor_jp(Uint32 col1, Uint32 col2, Uint32 col3);
void njSetBorderColor_jp(Uint32 color);
void njFrameBufferBmp_jp(char *bmp, char *buffer);
void njTextureFilterMode_jp(Int mode);
void njTextureClampMode_jp(Int mode);
void njTextureFlipMode_jp(Int mode);
void njColorBlendingMode_jp(Int target, Int mode);
void thunk_FUN_8c652c7a(Float size);
void njMemCopy_jp(void *dst, const void *src, Sint32 num);
void njMemCopy4_jp(void *dst, const void *src, Sint32 num);
extern NJS_MATRIX nj_unit_matrix_;
void pdExecPeripheralServerUser(void);
void DestroyTask(struct task *task);
void FreeTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
extern struct cameraControlWork camera_state_record;
extern Bool CamPathCam2Core_AliveFlag;
extern struct angles CamPathCam2Core_Angle;
extern struct cameraControlWork *const cameraControlWork;
void InitCartGoalCamFunc(struct camera_view *view);
void CameraSetEventCameraFunc(void (*step)(struct camera_view *view),
                              Uint8 adjust, Sint8 type);
void CameraReleaseEventCamera(void);
void CameraSetCollisionCameraFunc(void (*step)(struct camera_view *view),
                                  Uint8 adjust, Sint8 type);
void AmyBalanceGameStartChecker(struct camera_view *view);
extern struct near_task around_enemy_list_p0[1160 + 1];
extern struct near_task around_enemy_list_p1[1160 + 1];
extern struct collision_work *enemy_entry_num[128];
extern struct collision_work *enemy_colli_list2[256];
extern NJS_OBJECT object_sphere01;
extern NJS_OBJECT object_cylinder01;
extern NJS_OBJECT collision_dome_object;
void CCL_CalcRange(struct collision_work *collision);
void CCL_Init(struct task *task, const struct collision_shape *shapes,
              Uint8 kind, int unused, Uint8 count);
void EntryColliList(struct task_work *work);
void shape_get_center(struct task_work *work, struct collision_shape *shape,
                      NJS_POINT3 *pos);
Sint8 collision_get_hit_normal(struct task_work *work, NJS_VECTOR *normal_jp);
Bool OnEdit(struct task *task);
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
void ds_DrawModelClip(NJS_MODEL *model);
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
Float GetShadowPos(Float x, Float y, Float z, struct angles *slope);
void CharacterShadow(struct task_work *work, struct shadow *shadow);
extern struct task_motion *playermwp[];
extern struct task *playerpwp[8];
extern Uint8 playerframe[8];
void PInitialize(int player, struct task *task);
void PDestruct(int player);
void PAdjustHoldingPosition(struct task_work *work, struct task_motion *motion);
Bool PCheckPower(struct task_work *work, Angle *ang, Float *stroke);
void PGetAccelerationFly(struct task_work *work, struct task_motion *motion,
                         struct player *record);
void PSetSnowEffect(struct task_work *work, struct task_motion *motion,
                    struct player *record);
void PResetPositionForBuilding(struct task_work *work,
                               struct task_motion *motion,
                               struct player *record);
void PResetPosition(struct task_work *work, struct task_motion *motion,
                    struct player *record);
void PSetCrashEffect(struct task_work *work);
void KillPlayerFallingDownStageP(struct task *task);
void PSetRippleEffect(Uint8 player, NJS_POINT3 *pos, Angle *ang);
int CheckCollisionCylinderP(NJS_POINT3 *pos, Float radius, Float height);
int GetPlayerCharacterName(Uint8 player);
struct task *GetPlayerTaskPointer(Uint8 player);
struct player *GetPlayerWorkPointer(Uint8 player);
int GetTheNearestPlayerNumber(NJS_POINT3 *pos);
Bool CheckPlayerRideOnMobileLandObjectP(Uint8 player, struct task *task);
void SetLookingTaskP(Uint8 player, struct task *task, NJS_POINT3 *offset);
void SetLookingPointP(Uint8 player, NJS_POINT3 *pos);
void CancelLookingAtP(Uint8 player);
void HoldOnPillarP(Uint8 player, NJS_POINT3 *pos, Uint32 steps);
void KeepPlayersEyesOnThePointP(Uint8 player, struct angles *ang, Uint32 steps);
void SetInputP(Uint8 player, Uint8 mode);
void SetVelocityAndRotationAndNoconTimeWithSpinDashP(Uint8 player,
                                                     NJS_VECTOR *speed,
                                                     const Angle *ang,
                                                     Sint16 steps);
void SetPositionP(Uint8 player, Float x, Float y, Float z);
Bool GetPlayerPosition(Uint8 player, int steps, NJS_POINT3 *pos,
                       struct angles *ang);
extern Sint16 stage_retry_count;
extern Uint16 enemy_colli_list;
extern Uint16 enemy2_entry_num;
extern Sint8 ucMinutes;
extern Sint8 ucSeconds;
extern NJS_VECTOR VecTemp0;
extern NJS_VECTOR vG;
enum stage_group LoadTextureForEachGameMode(void);
void SetFinishAction(void);
int GetPlayerNumber(void);
Uint16 GetStageNumber(void);
Bool ChkPause(void);
extern PDS_PERIPHERAL perG[8];
extern PDS_PERIPHERAL *per[4];
extern struct pad_stick input_dataG[8];
void pause_enable(void);
Bool CheckPadReadMode(void);
void PadReadOnP(Uint8 player);
void PadReadOffP(Uint8 player);
void *syMalloc_default_malloc(size_t size);
Angle AdjustAngle(Angle from, Angle to, Angle step);
Angle DiffAngle(Angle from, Angle to);
Angle CreateNinjaAngle(Angle from, Angle to);
int VectorAngle(NJS_VECTOR *v1, NJS_VECTOR *v2, NJS_VECTOR *normal_jp);
Bool FrameIn(struct task_work *work);
void SaveConstantAttr(void);
void LoadConstantAttr(void);
void OnConstantAttr(Uint32 and_attr, Uint32 or_attr);
void OffConstantAttr(Uint32 and_attr, Uint32 or_attr);
void SaveControl3D(void);
void LoadControl3D(void);
void InterpolateModel(NJS_MODEL *from, NJS_MODEL *to, NJS_MODEL *out,
                      Float blend);
void InterpolatePointAsSin(NJS_POINT3 *from, NJS_POINT3 *to, NJS_POINT3 *out,
                           Float blend, int count);
void CalculatePointNormals(NJS_MODEL *model);
Bool MSetPosition(NJS_POINT3 *pos, NJS_VECTOR *speed, struct angles *ang,
                  Float radius);

/* the editor task's work->mode. the task's next step opens the editor in
 * OPENING, and closes it in CLOSING */
#define PRIORITIES 16
#define TAKE_RANGE 200.0F
#define MARKER_RANGE 400.0F
#define MARKER_SPHERE_RADIUS 10.0F
#define MARKER_SQUARE_HALF_SIZE 10.0F
#define MARKER_BOX_HALF_SIZE 5.0F
enum camera_editor_mode {
    CAMERA_EDITOR_INIT,
    CAMERA_EDITOR_CLOSED,
    CAMERA_EDITOR_OPEN,
    CAMERA_EDITOR_WAIT, /* stepped as CLOSED. nothing sets it */
    CAMERA_EDITOR_OPENING, /* camera_editor_request_open asks for it */
    CAMERA_EDITOR_CLOSING /* the system mode asks for it */
};

/* SET MODE on the console, kept in the work's submode: what the pad does */
enum console_mode { CONSOLE_SET, CONSOLE_SYSTEM, CONSOLE_MODES };

/* EDIT ELEMENT on the console: the edited collision's member that the pad
 * edits, named as the member is. ELEMENT_COLANG and ELEMENT_CAMANG each edit
 * an x and a y angle */
enum element {
    ELEMENT_COLPOS,
    ELEMENT_COLSCL,
    ELEMENT_COLANG,
    ELEMENT_CAMPOS,
    ELEMENT_DIRPOS,
    ELEMENT_CAMANG,
    ELEMENT_DISTANCE,
    ELEMENTS
};

/* how much of the console shows: all of it, its first seven rows, or none */
enum page { PAGE_ALL, PAGE_SHORT, PAGE_NONE, PAGES };
extern char camera_mode_names[72][32];
extern char adjust_mode_names[27][32];
extern char camcol_names[CAMCOL_TYPES][20];
extern char console_mode_names[CONSOLE_MODES][10];
extern char camera_level_names[CAMERA_LEVELS][16];
extern char element_names[ELEMENTS][20];
extern char camcol_type_names[CAMCOL_TYPES][20];
extern NJS_POINT3 cam_axis_points[6];
extern NJS_COLOR cam_axis_colors[6];
extern NJS_POINT3COL cam_axes;
extern struct task_work *cam_work;
extern Float cam_speed;
extern Bool cam_shown;
extern Sint16 cam_page;
extern Sint16 cam_mode;
extern Uint8 cam_adjust;
extern Sint16 cam_element;
extern Sint16 cam_level;
extern Float cam_float_delta;
extern int cam_hex_delta;
extern struct camera_collision cam_edited;
extern Sint16 cam_shape_blink;
extern Sint16 cam_float_blink;
extern Sint16 cam_hex_blink;

/* a blue square twenty across, the marker of a plane */
extern NJS_OBJECT marker_square_object;
/* yellow and red balls four across, which mark where a collision's camera
 * is and where it looks */
extern NJS_OBJECT marker_yellow_ball_object;
extern NJS_OBJECT marker_red_ball_object;

/* marker_object's radius, and the distance from the center of
 * marker_square_object and of marker_box_object to a side */

static void camera_editor_destroy(struct task *task);
static void collisions_draw_axes(void);
static void collisions_draw_markers(void);
void camera_editor_open(struct task_work *work);
void camera_editor_close(struct task_work *work);
void camera_editor_run(struct task_work *work);
static void camera_editor_set(struct task_work *work);
static void camera_editor_system(struct task_work *work);
static void element_take_camera(struct task_work *work);
static void element_move(struct task_work *work);
static void element_edit(struct task_work *work);
static void edited_draw_markers(struct task_work *work);
static void marker_draw_sphere(struct camera_collision *collision);
static void marker_draw_plane(struct camera_collision *collision);
static void marker_draw_block(struct camera_collision *collision);
static void marker_draw_camera(struct camera_collision *collision);
static void marker_draw_target(struct camera_collision *collision);
static void camera_editor_print(struct task_work *work);
static void cam_format_float(char *buffer, Float value, Sint16 element,
                             Sint16 axis);
static void cam_format_hex(char *buffer, int value, Sint16 element,
                           Sint16 axis);
static void edited_place_at_cursor(struct task_work *work);

static void camera_editor_step(struct task *task)
{
    struct task_work *work = task->work;

    /* @hack spelling: every case but the closed ones returns, which gives the
     * default and CAMERA_EDITOR_INIT returns of their own (0x8c01ce62,
     * 0x8c01ce72); with breaks, they branch to the closed cases', the
     * function runs 6 bytes short and 41 of 54 words differ */
    switch (work->mode) {
    default:
        return;
    case 0:
        cam_work = work;
        work->mode = 1;
        task->destructor = camera_editor_destroy;
        return;
    case 1:
        break;
    case 4:
        camera_editor_open(work);
        PadReadOff();
        pause_disable();
        return;
    case 2:
        camera_editor_run(work);
        return;
    case 5:
        work->mode = 1;
        ufExitSystem();
        pause_enable();
        camera_editor_close(work);
        return;
    case 3:
        break;
    }
}

/* the task's destructor. unless the editor is closed, it calls
 * debug_set_flag(0), as closing does. it leaves the pads, pause and the
 * camera as the editor set them */
static void camera_editor_destroy(struct task *task)
{
    struct task_work *work = task->work;

    if (work->mode == CAMERA_EDITOR_OPENING ||
        work->mode == CAMERA_EDITOR_OPEN ||
        work->mode == CAMERA_EDITOR_CLOSING) {
        debug_set_flag(0);
    }
}

/* while the act's collisions show, draw cam_axes at each but the first,
 * turned as the collision is. it draws only in a frame's first step */
static void collisions_draw_axes(void)
{
    struct camera_collision *collision;

    if (loop_count) {
        return;
    }
    if (cam_shown == TRUE) {
        for (collision = &camera_collisions[*camera_collision_count - 1];
             collision > camera_collisions; collision--) {
            njPushMatrix(NULL);
            njTranslate(NULL, collision->col_pos.x, collision->col_pos.y,
                        collision->col_pos.z);
            /* @hack type: the angles cast to Angle, which loads each into R11
             * and extends it once for the test and once for the call
             * (0x8c01cf56, 0x8c01cf68); as plain Uint16s, 37 of 77 words
             * differ */
            TURN(njRotateX, (Angle)collision->col_ang_x);
            TURN(njRotateY, (Angle)collision->col_ang_y);
            njDrawLine3D(&cam_axes, 3, NJD_DRAW_NORMAL);
            late_DrawObjectClipEx(1);
        }
    }
}

/* while the act's collisions show, draw the marker of each but the first
 * within MARKER_RANGE of the camera. it draws only in a frame's first step */
static void collisions_draw_markers(void)
{
    struct camera_collision *collision;
    NJS_VECTOR to_camera;

    if (loop_count) {
        return;
    }
    if (cam_shown == TRUE) {
        SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
        for (collision = &camera_collisions[*camera_collision_count - 1];
             collision > camera_collisions; collision--) {
            to_camera.x = camera_twp->pos.x - collision->col_pos.x;
            to_camera.y = camera_twp->pos.y - collision->col_pos.y;
            to_camera.z = camera_twp->pos.z - collision->col_pos.z;
            if (MARKER_RANGE > njScalor(&to_camera)) {
                switch (collision->type) {
                case CAMCOL_SPHERE:
                    marker_draw_sphere(collision);
                    break;
                case CAMCOL_PLANE:
                    marker_draw_plane(collision);
                    break;
                case CAMCOL_BLOCK:
                    marker_draw_block(collision);
                }
            }
        }
        SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
    }
}

/* open the editor in the set mode. the cursor starts at player 0, with the
 * edited collision placed there, and camera_orbit turns the camera about the
 * cursor */
void camera_editor_open(struct task_work *work)
{
    cam_float_delta = 1.0F;
    cam_hex_delta = 0x10;
    cam_element = ELEMENT_COLPOS;
    cam_speed = 1.0F;
    cam_level = CAMERA_LEVEL_NORMAL;
    cam_shown = TRUE;
    cam_page = PAGE_ALL;
    element_take_camera(work);
    cam_work = work;
    work->mode = CAMERA_EDITOR_OPEN;
    work->submode = CONSOLE_SET;
    work->pos = playertwp[0]->pos;
    work->ang = playertwp[0]->ang;
    edited_place_at_cursor(work);
    camera_take(work, camera_orbit);
}

void camera_editor_close(struct task_work *work)
{
    debug_set_flag(0);
    camera_release();
    work->mode = CAMERA_EDITOR_CLOSED;
}

void camera_editor_run(struct task_work *work)
{
    switch (work->submode) {
    case CONSOLE_SET:
        camera_editor_set(work);
        break;
    case CONSOLE_SYSTEM:
        camera_editor_system(work);
        break;
    }
    collisions_draw_axes();
    collisions_draw_markers();
    camera_editor_print(work);
}

/* the set mode, which edits cam_edited. with Start held, A takes a
 * collision out of the act's collisions to edit, and B adds a copy back. X
 * steps the adjust mode, and Y the shape. with A held, B turns to the system
 * mode, X steps the level, and Y the priority. up and down pick the element,
 * left and right the mode, and L and R slow or speed the cursor. with
 * neither held, element_move and element_edit edit the element */
static void camera_editor_set(struct task_work *work)
{
    struct camera_collision *collision;
    Sint16 i;
    Sint16 best;
    Float nearest;
    Float dx;
    Float dy;
    Float dz;
    Float distance;
    if (per[0]->on & (1 << 3)) {
        if (per[0]->press & (1 << 2)) {
            best = *camera_collision_count;
            nearest = TAKE_RANGE;
            collision = &camera_collisions[*camera_collision_count - 1];
            for (i = *camera_collision_count - 1; i >= 0; i--) {
                dx = collision->col_pos.x - work->pos.x;
                dy = collision->col_pos.y - work->pos.y;
                dz = collision->col_pos.z - work->pos.z;
                distance = njSqrt((dx * dx) + (dy * dy) + (dz * dz));
                if (distance < nearest) {
                    best = i;
                    nearest = distance;
                }
                collision--;
            }
            /* @hack type: the count compared as an Sint16, which SHC
             * sign-extends with EXTS.W at 0x8c01d2a8. the two compares agree
             * while the count fits an Sint16, as it does up to
             * CAMERA_COLLISIONS_MAX, the most the editor lets a layout hold;
             * compared whole, 114 of 521 words differ */
            if (best < (Sint16)*camera_collision_count) {
                (*camera_collision_count)--;
                collision = &camera_collisions[best];
                /* NOLINTBEGIN(bugprone-signed-char-misuse) */
                cam_mode = collision->mode;
                cam_adjust = collision->adjust;
                cam_level = camera_modes[cam_mode].level;
                /* NOLINTEND(bugprone-signed-char-misuse) */
                cam_edited = *collision;
                for (i = best; i < (Sint16)*camera_collision_count; i++) {
                    camera_collisions[i] = camera_collisions[(Sint32)i + 1];
                }
            }
            cam_element = ELEMENT_COLPOS;
            element_take_camera(work);
        } else if (per[0]->press & (1 << 1)) {
            if ((Uint32)*camera_collision_count < 0x1ff) {
                collision = &camera_collisions[(*camera_collision_count)++];
                *collision = cam_edited;
            }
            edited_place_at_cursor(work);
        } else if (per[0]->press & (1 << 10)) {
            if (++cam_adjust >= camera_adjust_count) {
                cam_adjust = 0;
            }
            cam_edited.adjust = cam_adjust;
        } else if (per[0]->press & (1 << 9)) {
            cam_edited.type++;
            if (cam_edited.type >= CAMCOL_TYPES) {
                cam_edited.type = CAMCOL_SPHERE;
            }
        }
    } else if (per[0]->on & (1 << 2)) {
        if (per[0]->press & (1 << 1)) {
            work->submode++;
            if (work->submode >= CONSOLE_MODES) {
                work->submode = CONSOLE_SET;
            }
        } else if (per[0]->press & (1 << 10)) {
            switch (cam_level) {
            case CAMERA_LEVEL_NORMAL:
                cam_level = CAMERA_LEVEL_AREA;
                break;
            case CAMERA_LEVEL_AREA:
                cam_level = CAMERA_LEVEL_COMP;
                break;
            case CAMERA_LEVEL_COMP:
                cam_level = CAMERA_LEVEL_COLI;
                break;
            case CAMERA_LEVEL_COLI:
                cam_level = CAMERA_LEVEL_NORMAL;
                break;
            }
            for (;;) {
                if (cam_level == camera_modes[cam_mode].level) {
                    cam_edited.mode = cam_mode;
                    break;
                }
                if (++cam_mode >= camera_mode_count) {
                    cam_mode = 0;
                }
            }
        } else if (per[0]->press & (1 << 9)) {
            cam_edited.priority++;
            if (cam_edited.priority >= PRIORITIES) {
                cam_edited.priority = 0;
            }
        } else if (per[0]->press & (1 << 4)) {
            cam_element--;
            if (cam_element < ELEMENT_COLPOS) {
                cam_element = ELEMENTS - 1;
            }
            element_take_camera(work);
        } else if (per[0]->press & (1 << 5)) {
            cam_element++;
            if (cam_element >= ELEMENTS) {
                cam_element = ELEMENT_COLPOS;
            }
            element_take_camera(work);
        } else if (per[0]->press & (1 << 6)) {
            for (;;) {
                if (--cam_mode < 0) {
                    cam_mode = camera_mode_count - 1;
                }
                if (cam_level == camera_modes[cam_mode].level) {
                    break;
                }
            }
            cam_edited.mode = cam_mode;
            element_take_camera(work);
        } else if (per[0]->press & (1 << 7)) {
            for (;;) {
                if (++cam_mode >= camera_mode_count) {
                    cam_mode = 0;
                }
                if (cam_level == camera_modes[cam_mode].level) {
                    break;
                }
            }
            cam_edited.mode = cam_mode;
            element_take_camera(work);
        } else if (per[0]->on & (1 << 17)) {
            cam_speed -= 0.1F;
            if (cam_speed < 0.0F) {
                cam_speed = 0.0F;
            }
        } else if (per[0]->on & (1 << 16)) {
            cam_speed += 0.1F;
        }
    } else {
        element_move(work);
        element_edit(work);
    }
    edited_draw_markers(work);
}

/* the system mode. with A held, B turns back to the set mode, and X closes
 * the editor. otherwise Y turns the console's page, and B shows or hides
 * the act's collisions. a press of X without A does nothing, and Y and B
 * pressed with it are ignored */
static void camera_editor_system(struct task_work *work)
{
    if (per[0]->on & (1 << 2)) {
        if (per[0]->press & (1 << 1)) {
            work->submode++;
            if (work->submode >= CONSOLE_MODES) {
                work->submode = CONSOLE_SET;
                /* @hack redundant: this return and the close's, which give each
                 * an RTS of its own with the store in its slot (0x8c01d704,
                 * 0x8c01d712); without them, 2 of 61 words differ */
                return;
            }
        } else if (per[0]->press & (1 << 10)) {
            work->mode = CAMERA_EDITOR_CLOSING;
            return;
        }
    } else if (per[0]->press & (1 << 10)) {
    } else if (per[0]->press & (1 << 9)) {
        cam_page++;
        if (cam_page >= PAGES) {
            cam_page = PAGE_ALL;
            /* @hack redundant: this return, where control leaves anyway,
             * which gives the page's wrap an RTS of its own with the store in
             * its slot (0x8c01d73a), as the mode's wrap has; without it, 1 of
             * 61 words differ */
            return;
        }
    } else if (per[0]->press & (1 << 1)) {
        cam_shown = cam_shown == (1) ? (0) : (1);
    }
}

/* take the camera for the element. the collision's elements take
 * camera_orbit, which turns the camera about the cursor. the camera's points
 * and distance take the edited mode's editor step, or camera_orbit where it
 * has none. ELEMENT_CAMANG keeps the camera already taken */
static void element_take_camera(struct task_work *work)
{
    struct camera_mode *mode;

    switch (cam_element) {
    case ELEMENT_COLPOS:
    case ELEMENT_COLSCL:
    case ELEMENT_COLANG:
        camera_take(work, camera_orbit);
        break;
    case ELEMENT_CAMPOS:
    case ELEMENT_DIRPOS:
    case ELEMENT_DISTANCE:
        mode = &camera_modes[cam_mode];
        if (mode->editor == NULL) {
            camera_take(work, camera_orbit);
        } else {
            camera_take(work, mode->editor);
        }
        break;
    }
}

/* move the cursor by cam_speed in each step, and the element's point with
 * it: col_pos for the collision's elements, or cam_pos or dir_pos. the
 * cursor first goes to the point. up and down move it away from the camera
 * and back, left and right across, and L and R up and down. it moves
 * nothing for ELEMENT_CAMANG or ELEMENT_DISTANCE, or with A, B, X or Y held */
static void element_move(struct task_work *work)
{
    NJS_POINT3 *point;
    Float *y;
    Float *z;
    Angle ang;

    ang = camera_twp->ang.y;
    if (cam_element == ELEMENT_CAMANG || cam_element == ELEMENT_DISTANCE) {
        return;
    }
    if (per[0]->on & ((1 << 1) | (1 << 2) | (1 << 9) | (1 << 10))) {
        return;
    }
    switch (cam_element) {
    case ELEMENT_COLPOS:
    case ELEMENT_COLSCL:
    case ELEMENT_COLANG:
        point = &cam_edited.col_pos;
        break;
    case ELEMENT_CAMPOS:
        point = &cam_edited.cam_pos;
        break;
    case ELEMENT_DIRPOS:
        point = &cam_edited.dir_pos;
        break;
    default:
        return;
    }
    work->pos.x = point->x;
    /* @hack spelling: y and z taken in the reads, which leaves them in the
     * 8-byte frame (ADD #-8,R15 at 0x8c01d80c); taken apart, the prologue
     * saves R8 and R9 for them instead and 116 of 199 words differ */
    work->pos.y = *(y = &point->y);
    work->pos.z = *(z = &point->z);
    if (per[0]->on & ((1 << 4) | (1 << 5) | (1 << 6) | (1 << 7))) {
        if (per[0]->on & (1 << 4)) {
            if (per[0]->on & (1 << 6)) {
                ang += 0xa000;
            } else if (per[0]->on & (1 << 7)) {
                ang += 0x6000;
            } else {
                ang += 0x8000;
            }
        } else if (per[0]->on & (1 << 5)) {
            if (per[0]->on & (1 << 6)) {
                ang += 0xe000;
            } else if (per[0]->on & (1 << 7)) {
                ang += 0x2000;
            } else {
                /* @hack redundant: down alone adds 0, an arm SHC keeps as a
                 * BT straight to the move (0x8c01d946); without it, 3 of 199
                 * words differ */
                ang += 0x0000;
            }
        } else if (per[0]->on & (1 << 6)) {
            ang += 0xc000;
        } else if (per[0]->on & (1 << 7)) {
            ang += 0x4000;
        }
        work->pos.z += njCos(ang) * cam_speed;
        work->pos.x += njSin(ang) * cam_speed;
    }
    if (per[0]->on & ((1 << 16) | (1 << 17))) {
        if (per[0]->on & (1 << 17)) {
            work->pos.y += cam_speed;
        } else if (per[0]->on & (1 << 16)) {
            work->pos.y -= cam_speed;
        }
    }
    point->x = work->pos.x;
    *y = work->pos.y;
    *z = work->pos.z;
}

/* edit the element's value. a press of left makes its delta 10 times
 * bigger, or 16 for an angle, and right as many times smaller. up adds the
 * delta and down takes it away, in each step they're held. they edit x with
 * X held, y with Y and z with B, which for an angle lies past its y angle.
 * the distance takes X alone */
static void element_edit(struct task_work *work)
{
    Uint16 *angle;
    NJS_POINT3 *point;
    Float *y;
    Float *z;

    if (cam_element == ELEMENT_DISTANCE) {
        if (per[0]->press & (1 << 6)) {
            cam_float_delta *= 10.0F;
            if (cam_float_delta > 100.0F) {
                cam_float_delta = 100.0F;
            }
        } else if (per[0]->press & (1 << 7)) {
            cam_float_delta *= 0.1F;
            if (cam_float_delta < 0.1F) {
                cam_float_delta = 0.1F;
            }
        }
        if (per[0]->on & (1 << 10)) {
            if (per[0]->on & (1 << 4)) {
                cam_edited.distance += cam_float_delta;
            }
            if (per[0]->on & (1 << 5)) {
                cam_edited.distance -= cam_float_delta;
            }
        }
    } else if (cam_element == ELEMENT_COLANG || cam_element == ELEMENT_CAMANG) {
        if (per[0]->press & (1 << 6)) {
            cam_hex_delta *= 16;
            if (cam_hex_delta > 0x1000) {
                cam_hex_delta = 0x1000;
            }
        } else if (per[0]->press & (1 << 7)) {
            cam_hex_delta /= 16;
            if (cam_hex_delta < 1) {
                cam_hex_delta = 1;
            }
        }
        /* @hack spelling: angle, a Uint16 cursor from col_ang_x or cam_ang_x,
         * reaches the y angle beside it as angle[1]; without it, through a
         * byte cursor from the record's base, 148 of 363 words differ */
        if (cam_element == ELEMENT_COLANG) {
            angle = &cam_edited.col_ang_x;
        } else {
            angle = &cam_edited.cam_ang_x;
        }
        if (per[0]->on & (1 << 10)) {
            if (per[0]->on & (1 << 4)) {
                angle[0] += (Uint16)cam_hex_delta;
            }
            if (per[0]->on & (1 << 5)) {
                angle[0] -= (Uint16)cam_hex_delta;
            }
        } else if (per[0]->on & (1 << 9)) {
            if (per[0]->on & (1 << 4)) {
                angle[1] += (Uint16)cam_hex_delta;
            }
            if (per[0]->on & (1 << 5)) {
                angle[1] -= (Uint16)cam_hex_delta;
            }
        } else if (per[0]->on & (1 << 1)) {
            if (per[0]->on & (1 << 4)) {
                angle[2] += (Uint16)cam_hex_delta;
            }
            if (per[0]->on & (1 << 5)) {
                angle[2] -= (Uint16)cam_hex_delta;
            }
        }
    } else {
        point = ((void *)0);
        if (per[0]->press & (1 << 6)) {
            cam_float_delta *= 10.0F;
            if (cam_float_delta > 100.0F) {
                cam_float_delta = 100.0F;
            }
        } else if (per[0]->press & (1 << 7)) {
            cam_float_delta *= 0.1F;
            if (cam_float_delta < 0.1F) {
                cam_float_delta = 0.1F;
            }
        }
        switch (cam_element) {
        case ELEMENT_COLPOS:
            point = &cam_edited.col_pos;
            break;
        case ELEMENT_COLSCL:
            point = &cam_edited.col_scl;
            /* a sphere's radius follows its square, which the pad edits as
             * z */
            if (cam_edited.type == CAMCOL_SPHERE) {
                cam_edited.col_scl.x = njSqrt(cam_edited.col_scl.z);
            }
            break;
        case ELEMENT_CAMPOS:
            point = &cam_edited.cam_pos;
            break;
        case ELEMENT_DIRPOS:
            point = &cam_edited.dir_pos;
            break;
        }
        if (y = &point->y, z = &point->z, per[0]->on & (1 << 10)) {
            if (per[0]->on & (1 << 4)) {
                point->x += cam_float_delta;
            }
            if (per[0]->on & (1 << 5)) {
                point->x -= cam_float_delta;
            }
        } else if (per[0]->on & (1 << 9)) {
            if (per[0]->on & (1 << 4)) {
                *y += cam_float_delta;
            }
            if (per[0]->on & (1 << 5)) {
                *y -= cam_float_delta;
            }
        } else if (per[0]->on & (1 << 1)) {
            if (per[0]->on & (1 << 4)) {
                *z += cam_float_delta;
            }
            if (per[0]->on & (1 << 5)) {
                *z -= cam_float_delta;
            }
        }
        /* the cursor follows an edited point. a scale isn't a place: the
         * cursor stays, and no axis of the scale goes below 0 */
        if (cam_element != ELEMENT_COLSCL) {
            work->pos.x = point->x;
            work->pos.y = *y;
            work->pos.z = *z;
        } else {
            if (point->x < 0.0F) {
                point->x = 0.0F;
            }
            if (*y < 0.0F) {
                *y = 0.0F;
            }
            if (*z < 0.0F) {
                *z = 0.0F;
            }
        }
    }
}

/* draw the cursor's axes and the edited collision's markers. while the pad
 * edits one of the camera's elements, the shape's marker blinks */
static void edited_draw_markers(struct task_work *work)
{
    debug_draw_axes(work);
    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
    if (cam_element == ELEMENT_COLPOS || cam_element == ELEMENT_COLSCL ||
        cam_element == ELEMENT_COLANG || (cam_shape_blink++ & 8)) {
        switch (cam_edited.type) {
        case CAMCOL_SPHERE:
            marker_draw_sphere(&cam_edited);
            break;
        case CAMCOL_PLANE:
            marker_draw_plane(&cam_edited);
            break;
        case CAMCOL_BLOCK:
            marker_draw_block(&cam_edited);
            break;
        default:
            break;
        }
    }

    marker_draw_target(&cam_edited);
    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
}

/* draw the marker of a sphere, a plane or a block at the collision's
 * col_pos. a sphere's takes its radius. a plane's or block's takes its half
 * sizes, and turns by its angles */
static void marker_draw_sphere(struct camera_collision *collision)
{
    Float scale = njSqrt(collision->col_scl.z) * (1.0F / MARKER_SPHERE_RADIUS);

    njPushMatrix(NULL);
    njTranslate(NULL, collision->col_pos.x, collision->col_pos.y,
                collision->col_pos.z);
    njScale(NULL, scale, scale, scale);
    ds_DrawModelClip(object_sphere01.model);
    late_DrawObjectClipEx(1);
}

static void marker_draw_plane(struct camera_collision *collision)
{
    Float x = collision->col_scl.x * (1.0F / MARKER_SQUARE_HALF_SIZE);
    Float y = collision->col_scl.y * (1.0F / MARKER_SQUARE_HALF_SIZE);

    njPushMatrix(NULL);
    njTranslate(NULL, collision->col_pos.x, collision->col_pos.y,
                collision->col_pos.z);
    /* @hack type: the angles cast to Angle, which extends each once and
     * keeps it in the frame across its test (0x8c01df2a, 0x8c01df3c); as
     * plain Uint16s, 35 of 64 words differ */
    TURN(njRotateX, (Angle)collision->col_ang_x);
    TURN(njRotateY, (Angle)collision->col_ang_y);
    njScale(NULL, x, y, 1.0F);
    ds_DrawModelClip(marker_square_object.model);
    late_DrawObjectClipEx(1);
}

static void marker_draw_block(struct camera_collision *collision)
{
    Float x = collision->col_scl.x * (1.0F / MARKER_BOX_HALF_SIZE);
    Float y = collision->col_scl.y * (1.0F / MARKER_BOX_HALF_SIZE);
    Float z = collision->col_scl.z * (1.0F / MARKER_BOX_HALF_SIZE);

    njPushMatrix(NULL);
    njTranslate(NULL, collision->col_pos.x, collision->col_pos.y,
                collision->col_pos.z);
    /* @hack type: the angles cast to Angle, as in marker_draw_plane
     * (0x8c01dfb4, 0x8c01dfc6); as plain Uint16s, 36 of 70 words differ */
    TURN(njRotateX, (Angle)collision->col_ang_x);
    TURN(njRotateY, (Angle)collision->col_ang_y);
    njScale(NULL, x, y, z);
    ds_DrawModelClip(marker_box_object.model);
    late_DrawObjectClipEx(1);
}

/* draw the yellow ball at the collision's cam_pos, and the red one at its
 * dir_pos, where its camera looks */
static void marker_draw_camera(struct camera_collision *collision)
{
    njPushMatrix(NULL);
    njTranslate(NULL, collision->cam_pos.x, collision->cam_pos.y,
                collision->cam_pos.z);
    ds_DrawModelClip(marker_yellow_ball_object.model);
    late_DrawObjectClipEx(1);
}

static void marker_draw_target(struct camera_collision *collision)
{
    njPushMatrix(NULL);
    njTranslate(NULL, collision->dir_pos.x, collision->dir_pos.y,
                collision->dir_pos.z);
    ds_DrawModelClip(marker_red_ball_object.model);
    late_DrawObjectClipEx(1);
}

/* print the console's rows that cam_page shows, each a label and a value.
 * the first seven show the editor's own settings and cam_edited's shape. at
 * PAGE_ALL, the rest show cam_edited's fields. it prints only in a frame's
 * first step */
static void camera_editor_print(struct task_work *work)
{
    char buf[32];
    Sint16 row;

    row = 3;
    if (loop_count) {
        return;
    }
    if (cam_page <= PAGE_SHORT) {
        njPrintC(NJM_LOCATION(5, row++), "SET    MODE:");
        njPrintC(NJM_LOCATION(5, row++), "CAMERA MODE:");
        njPrintC(NJM_LOCATION(5, row++), "CAMERA LEVEL:");
        njPrintC(NJM_LOCATION(5, row++), "EDIT ELEMENT:");
        njPrintC(NJM_LOCATION(5, row++), "COLLISION TYPE:");
        njPrintC(NJM_LOCATION(5, row++), "MOVING SPEED:");
        njPrintC(NJM_LOCATION(5, row++), "ADJUST MODE:");
        if (cam_page == PAGE_ALL) {
            njPrintC(NJM_LOCATION(5, row++), "PRIORITY:");
            njPrintC(NJM_LOCATION(5, row++), "X COLPOS:");
            njPrintC(NJM_LOCATION(5, row++), "Y COLPOS:");
            njPrintC(NJM_LOCATION(5, row++), "Z COLPOS:");
            njPrintC(NJM_LOCATION(5, row++), "X COLSCL:");
            njPrintC(NJM_LOCATION(5, row++), "Y COLSCL:");
            njPrintC(NJM_LOCATION(5, row++), "Z COLSCL:");
            njPrintC(NJM_LOCATION(5, row++), "X COLANG:");
            njPrintC(NJM_LOCATION(5, row++), "Y COLANG:");
            njPrintC(NJM_LOCATION(5, row++), "X CAMPOS:");
            njPrintC(NJM_LOCATION(5, row++), "Y CAMPOS:");
            njPrintC(NJM_LOCATION(5, row++), "Z CAMPOS:");
            njPrintC(NJM_LOCATION(5, row++), "X DIRPOS:");
            njPrintC(NJM_LOCATION(5, row++), "Y DIRPOS:");
            njPrintC(NJM_LOCATION(5, row++), "Z DIRPOS:");
            njPrintC(NJM_LOCATION(5, row++), "X CAMANG:");
            njPrintC(NJM_LOCATION(5, row++), "Y CAMANG:");
            njPrintC(NJM_LOCATION(5, row++), "DISTANCE:");
        }
    }
    row = 3;
    if (cam_page > PAGE_SHORT) {
        return;
    }
    njPrintC(NJM_LOCATION(18, row++), console_mode_names[work->submode]);
    njPrintC(NJM_LOCATION(18, row++), camera_mode_names[cam_mode]);
    njPrintC(NJM_LOCATION(18, row++), camera_level_names[cam_level]);
    njPrintC(NJM_LOCATION(18, row++), element_names[cam_element]);
    njPrintC(NJM_LOCATION(22, row++), camcol_type_names[cam_edited.type]);
    sprintf(buf, "%8.2f", cam_speed);
    njPrintC(NJM_LOCATION(20, row++), buf);
    njPrintC(NJM_LOCATION(18, row++), adjust_mode_names[cam_adjust]);
    if (cam_page != PAGE_ALL) {
        return;
    }
    FUN_8c6409c0(((18) << 16 | (row++)), cam_edited.priority, 10);
    cam_format_float(buf, cam_edited.col_pos.x, ELEMENT_COLPOS, 0);
    njPrintC(NJM_LOCATION(18, row++), buf);
    cam_format_float(buf, cam_edited.col_pos.y, ELEMENT_COLPOS, 1);
    njPrintC(NJM_LOCATION(18, row++), buf);
    cam_format_float(buf, cam_edited.col_pos.z, ELEMENT_COLPOS, 2);
    njPrintC(NJM_LOCATION(18, row++), buf);
    cam_format_float(buf, cam_edited.col_scl.x, ELEMENT_COLSCL, 0);
    njPrintC(NJM_LOCATION(18, row++), buf);
    cam_format_float(buf, cam_edited.col_scl.y, ELEMENT_COLSCL, 1);
    njPrintC(NJM_LOCATION(18, row++), buf);
    cam_format_float(buf, cam_edited.col_scl.z, ELEMENT_COLSCL, 2);
    njPrintC(NJM_LOCATION(18, row++), buf);
    cam_format_hex(buf, cam_edited.col_ang_x, ELEMENT_COLANG, 0);
    njPrintC(NJM_LOCATION(20, row++), buf);
    cam_format_hex(buf, cam_edited.col_ang_y, ELEMENT_COLANG, 1);
    njPrintC(NJM_LOCATION(20, row++), buf);
    cam_format_float(buf, cam_edited.cam_pos.x, ELEMENT_CAMPOS, 0);
    njPrintC(NJM_LOCATION(18, row++), buf);
    cam_format_float(buf, cam_edited.cam_pos.y, ELEMENT_CAMPOS, 1);
    njPrintC(NJM_LOCATION(18, row++), buf);
    cam_format_float(buf, cam_edited.cam_pos.z, ELEMENT_CAMPOS, 2);
    njPrintC(NJM_LOCATION(18, row++), buf);
    cam_format_float(buf, cam_edited.dir_pos.x, ELEMENT_DIRPOS, 0);
    njPrintC(NJM_LOCATION(18, row++), buf);
    cam_format_float(buf, cam_edited.dir_pos.y, ELEMENT_DIRPOS, 1);
    njPrintC(NJM_LOCATION(18, row++), buf);
    cam_format_float(buf, cam_edited.dir_pos.z, ELEMENT_DIRPOS, 2);
    njPrintC(NJM_LOCATION(18, row++), buf);
    cam_format_hex(buf, cam_edited.cam_ang_x, ELEMENT_CAMANG, 0);
    njPrintC(NJM_LOCATION(20, row++), buf);
    cam_format_hex(buf, cam_edited.cam_ang_y, ELEMENT_CAMANG, 1);
    njPrintC(NJM_LOCATION(20, row++), buf);
    cam_format_float(buf, cam_edited.distance, ELEMENT_DISTANCE, 0);
    njPrintC(NJM_LOCATION(18, row++), buf);
}

/* write value into buffer. while the pad edits it, the digit that
 * cam_float_delta changes blinks */
static void cam_format_float(char *buffer, Float value, Sint16 element,
                             Sint16 axis)
{
    sprintf(buffer, "%10.4f", value);
    if (((axis == 0 && (per[0]->on & (1 << 10))) ||
         (axis == 1 && (per[0]->on & (1 << 9))) ||
         (axis == 2 && (per[0]->on & (1 << 1)))) &&
        element == cam_element && (cam_float_blink++ & 8)) {
        /* @hack spelling: each constant on the left, which puts the delta first
         * in each FCMP/EQ (FCMP/EQ FR4,FR3 at 0x8c01e578); on the right, 6 of
         * 117 words differ */
        /* @hack redundant: a return in each arm but the last, which gives each
         * arm an epilogue and RTS of its own (0x8c01e586, 0x8c01e59a);
         * without them, 82 of 117 words differ and the code runs 32 bytes
         * short */
        if (0.01F == cam_float_delta) {
            buffer[7] = ' ';
            return;
        } else if (0.1F == cam_float_delta) {
            buffer[6] = ' ';
            return;
        } else if (1.0F == cam_float_delta) {
            buffer[4] = ' ';
            return;
        } else if (10.0F == cam_float_delta) {
            buffer[3] = ' ';
            return;
        } else if (100.0F == cam_float_delta) {
            buffer[2] = ' ';
            return;
        } else if (1000.0F == cam_float_delta) {
            buffer[1] = ' ';
        }
    }
}

/* as cam_format_float, for an angle, with the digit cam_hex_delta changes
 * blinking */
static void cam_format_hex(char *buffer, int value, Sint16 element, Sint16 axis)
{
    sprintf(buffer, "%08x", value);
    if (((axis == 0 && (per[0]->on & (1 << 10))) ||
         (axis == 1 && (per[0]->on & (1 << 9)))) &&
        element == cam_element && (cam_hex_blink++ & 8)) {
        /* @hack redundant: a return in each arm but the last, which puts each
         * arm's store in the slot of its own BRA to the epilogue (0x8c01e6c8
         * to 0x8c01e728); without them, 44 of 93 words differ and the code
         * runs 32 bytes short */
        if (cam_hex_delta == 1) {
            buffer[7] = ' ';
            return;
        } else if (cam_hex_delta == 0x10) {
            buffer[6] = ' ';
            return;
        } else if (cam_hex_delta == 0x100) {
            buffer[5] = ' ';
            return;
        } else if (cam_hex_delta == 0x1000) {
            buffer[4] = ' ';
            return;
        } else if (cam_hex_delta == 0x10000) {
            buffer[3] = ' ';
        }
    }
}

void camera_step_editor(struct camera_view *view)
{
    view->pos.x = cam_edited.cam_pos.x;
    view->pos.y = cam_edited.cam_pos.y;
    view->pos.z = cam_edited.cam_pos.z;
    view->target.x = cam_edited.dir_pos.x;
    view->target.y = cam_edited.dir_pos.y;
    view->target.z = cam_edited.dir_pos.z;
    view->ang_x = cam_edited.cam_ang_x;
    view->ang_y = cam_edited.cam_ang_y;
}

/* place the edited collision at the cursor, with a scale of 10 each way and
 * every angle 0. its camera looks at the cursor from 15 above it and 50
 * out, along z turned by the cursor's y angle. the collision keeps its
 * mode, adjust mode, priority, shape and distance */
static void edited_place_at_cursor(struct task_work *work)
{
    cam_edited.col_pos.x = work->pos.x;
    cam_edited.col_pos.y = work->pos.y;
    cam_edited.col_pos.z = work->pos.z;
    cam_edited.col_scl.x = 10.0F;
    cam_edited.col_scl.y = 10.0F;
    cam_edited.col_scl.z = 10.0F;
    cam_edited.col_ang_x = 0;
    cam_edited.col_ang_y = 0;
    cam_edited.cam_ang_x = 0;
    cam_edited.cam_ang_y = 0;
    cam_edited.dir_pos.x = cam_edited.col_pos.x = work->pos.x;
    cam_edited.dir_pos.y = cam_edited.col_pos.y = work->pos.y;
    cam_edited.dir_pos.z = cam_edited.col_pos.z = work->pos.z;
    cam_edited.cam_pos.y = cam_edited.dir_pos.y + 15.0F;
    cam_edited.cam_pos.x = cam_edited.dir_pos.x + (njSin(work->ang.y) * 50.0F);
    cam_edited.cam_pos.z = cam_edited.dir_pos.z + (njCos(work->ang.y) * 50.0F);
}

void camera_editor_create(void)
{
    CreateElementalTask(TASK_WORK, 1, camera_editor_step);
}

int camera_editor_request_open(void)
{
    struct task_work *work = cam_work;

    if (work == NULL) {
        return -1;
    }
    switch (work->mode) {
    case CAMERA_EDITOR_CLOSED:
        work->mode = CAMERA_EDITOR_OPENING;
        break;
    case CAMERA_EDITOR_CLOSING:
        return -1;
    }
    return 0;
}

/* the message, by its words, for saving the act's collisions. no code
 * calls it. SHC leaves the function out, but keeps its string at
 * 0x8c1292f8 */
/* NOLINTNEXTLINE(clang-diagnostic-unused-function) */
static const char *camera_editor_saving(void)
{
    return "SAVING.........";
}
extern char *camera_folders[15 + 1];

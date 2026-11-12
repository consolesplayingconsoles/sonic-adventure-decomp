/* samples: stand-ins, drawn as the marker cylinder, for things a player
 * carries, in three sizes, and for one the player shakes */
#ifndef OBJECT_SAMPLE_H
#define OBJECT_SAMPLE_H

#include "system/task.h"

/* the first steps of SAMPLE S, M, L and SW, kinds of object the Mystic
 * Ruins place. each sets its sample up and gives the task the sample's own
 * step */
void ObjectSampleS(struct task *task);
void ObjectSampleM(struct task *task);
void ObjectSampleL(struct task *task);
void ObjectSampleSW(struct task *task);

#endif

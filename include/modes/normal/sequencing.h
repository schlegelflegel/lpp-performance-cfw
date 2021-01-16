#ifndef SEQUENCING_H
#define SEQUENCING_H

#include "app.h"
#include "modes/mode.h"
#include "send/send.h"

#include "aftertouch/aftertouch.h"

#define mode_sequencing_r 0
#define mode_sequencing_g 63
#define mode_sequencing_b 15

void sequencing_init();
void sequencing_timer_event();
void sequencing_surface_event(u8 p, u8 v, u8 x, u8 y);
void sequencing_midi_event(u8 port, u8 t, u8 ch, u8 p, u8 v);
void sequencing_aftertouch_event(u8 v);
void sequencing_poly_event(u8 p, u8 v);

#endif
#ifndef SEQUENCER_H
#define SEQUENCER_H

#include "app.h"
#include "modes/mode.h"
#include "send/send.h"

#include "aftertouch/aftertouch.h"

#define mode_sequencer_r 15
#define mode_sequencer_g 63
#define mode_sequencer_b 0

void sequencer_init();
void sequencer_timer_event();
void sequencer_surface_event(u8 p, u8 v, u8 x, u8 y);
void sequencer_midi_event(u8 port, u8 t, u8 ch, u8 p, u8 v);
void sequencer_aftertouch_event(u8 v);
void sequencer_poly_event(u8 p, u8 v);

#endif
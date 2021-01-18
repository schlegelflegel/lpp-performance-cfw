#ifndef SEQUENCER_H
#define SEQUENCER_H

#include "sequencer/playhead.h"


#define SEQUENCER_TICKS_PER_SECOND 1050 // timer events per second

#define SEQUENCER_PPQ 24 // pulses per quarter note
#define SEQUENCER_PPS (SEQUENCER_PPQ / 4) // pulses per sixteenth note

#define SEQUENCER_BPM_MIN 20
#define SEQUENCER_BPM_MAX 500

#define SEQUENCER_SWING_MIN 50
#define SEQUENCER_SWING_MAX 75


typedef struct sequencer {
    playhead_t playhead;

    unsigned int running;

    unsigned int tick_count;
    unsigned int tick_limit;

    unsigned int bpm;
    unsigned int swing;

    unsigned int seqlength;
} sequencer_t;

typedef void (*sequencer_redraw_callback_t)();

sequencer_t sequencer;
sequencer_redraw_callback_t sequencer_redraw_callback;


void sequencer_init();

void sequencer_update();

void sequencer_play();

void sequencer_stop();

void sequencer_set_bpm(unsigned int bpm);

void sequencer_set_swing(unsigned int swing);


#endif

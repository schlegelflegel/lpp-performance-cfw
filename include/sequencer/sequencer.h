#ifndef SEQUENCER_H
#define SEQUENCER_H

#include "sequencer/playhead.h"


#define SEQUENCER_TICKS_PER_SECOND 1050 // timer events per second
#define SEQUENCER_PPQ 24 // pulses per quarter note

#define SEQUENCER_BPMCT_MIN 2000
#define SEQUENCER_BPMCT_MAX 50000


struct sequencer {
    struct playhead ph;

    unsigned int tick_count;
    unsigned int tick_limit;
    unsigned int bpmct; // 120 bpm => 12000 bpmct "bpm percent"

    unsigned int seqlength;
};


void sequencer_init(struct sequencer *seq);

void sequencer_update(struct sequencer *seq);

void sequencer_set_bpm(struct sequencer *seq, unsigned int bpmct);


#endif

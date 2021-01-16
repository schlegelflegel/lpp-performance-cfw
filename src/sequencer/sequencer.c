#include "sequencer/sequencer.h"

void sequencer_init(struct sequencer *seq) {
    playhead_init(&seq->ph);

    seq->tick_count = 0;
    sequencer_set_bpm(seq, 12000);

    seq->seqlength = 4;
}

void sequencer_update(struct sequencer *seq) {
    seq->tick_count++;

    // we got a pulse
    if (seq->tick_count >= seq->tick_limit) {
        seq->tick_count = 0;

        playhead_pulse(&seq->ph, seq->seqlength * SEQUENCER_PPQ);
    }
}

void sequencer_set_bpm(struct sequencer *seq, unsigned int bpmct) {
    if (seq->bpmct == bpmct) return;
	if (bpmct < SEQUENCER_BPMCT_MIN) bpmct = SEQUENCER_BPMCT_MIN;
	if (bpmct > SEQUENCER_BPMCT_MAX) bpmct = SEQUENCER_BPMCT_MAX;

    // convert bpmct => ticks per pulse
    seq->bpmct = bpmct;
	seq->tick_limit = SEQUENCER_TICKS_PER_SECOND * 60 * 100 / SEQUENCER_PPQ / bpmct;
}

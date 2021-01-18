#include "sequencer/playhead.h"

#include "app.h"


void playhead_init(playhead_t *ph) {
    playhead_reset(ph);
}


void playhead_pulse(playhead_t *ph, unsigned int seqlength) {
    unsigned int position = ph->clock + 1;
    if (position >= seqlength * SEQUENCER_PPS) position = 0;

	playhead_set(ph, position);
}


void playhead_reset(playhead_t *ph) {
	playhead_set(ph, 0);
}


void playhead_set(playhead_t *ph, unsigned int clock) {
    if (ph->clock == clock) return;

	ph->clock = clock;
	ph->position = clock / SEQUENCER_PPS;
	ph->bars = ph->position / 16;
}

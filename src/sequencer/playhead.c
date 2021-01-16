#include "sequencer/playhead.h"

#include "app.h"


void playhead_init(struct playhead *ph) {
    playhead_reset(ph);
}


void playhead_pulse(struct playhead *ph, unsigned int position_length) {
    unsigned int position = ph->position + 1;
    if (position >= position_length) position = 0;

	playhead_set(ph, position);
}


void playhead_reset(struct playhead *ph) {
	playhead_set(ph, 0);
}


void playhead_set(struct playhead *ph, unsigned int clock) {
    if (ph->position == clock) return;

	ph->position = clock;
	ph->thirtysecond = ph->position / 3;
	ph->sixteenth = ph->thirtysecond >> 1;
	ph->eighth = ph->sixteenth >> 1;
	ph->quarter = ph->eighth >> 1;
	ph->half = ph->quarter >> 1;
	ph->whole = ph->quarter >> 1;
	ph->bars = ph->bars;
}

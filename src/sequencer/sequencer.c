#include "sequencer/sequencer.h"


sequencer_t sequencer;
sequencer_redraw_callback_t sequencer_redraw_callback;


void sequencer_init() {
    playhead_init(&sequencer.playhead);

    sequencer.tick_count = 0;
    sequencer_set_bpm(120);
    sequencer_set_swing(50);

    sequencer.seqlength = 32;
}


void sequencer_update() {
    if (!sequencer.running) return;

    unsigned int prev_position;
    unsigned int tick_limit;
    unsigned int is_odd = (sequencer.playhead.position / 2) % 2;

    if (is_odd) {
        tick_limit = sequencer.tick_limit * (100 - sequencer.swing) / 50;
    } else {
        tick_limit = sequencer.tick_limit * sequencer.swing / 50;
    }

    sequencer.tick_count++;
    if (sequencer.tick_count >= tick_limit) {
        sequencer.tick_count = 0;

        prev_position = sequencer.playhead.position;
        playhead_pulse(&sequencer.playhead, sequencer.seqlength);

        if (sequencer.playhead.position != prev_position && sequencer_redraw_callback) {
            (*sequencer_redraw_callback)();
        }
    }
}


void sequencer_play() {
    sequencer.running = 1;

    if (sequencer_redraw_callback) (*sequencer_redraw_callback)();
}


void sequencer_stop() {
    sequencer.running = 0;
    sequencer.tick_count = 0;

    playhead_reset(&sequencer.playhead);
}


void sequencer_set_bpm(unsigned int bpm) {
    if (sequencer.bpm == bpm) return;
	if (bpm < SEQUENCER_BPM_MIN) bpm = SEQUENCER_BPM_MIN;
	if (bpm > SEQUENCER_BPM_MAX) bpm = SEQUENCER_BPM_MAX;

    // convert bpm => ticks per pulse
    sequencer.bpm = bpm;
	sequencer.tick_limit = SEQUENCER_TICKS_PER_SECOND * 60 / SEQUENCER_PPQ / bpm;
}


void sequencer_set_swing(unsigned int swing) {
    if (sequencer.swing == swing) return;
	if (swing < SEQUENCER_SWING_MIN) swing = SEQUENCER_SWING_MIN;
	if (swing > SEQUENCER_SWING_MAX) swing = SEQUENCER_SWING_MAX;

    sequencer.swing = swing;
}

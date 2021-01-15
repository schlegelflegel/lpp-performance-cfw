#include "modes/normal/sequencer.h"


#define SEQUENCER_PLAYHEAD_LED(pos) (81 + (pos) - 18 * ((pos) >> 3))


unsigned int sequencer_bpm;
unsigned int sequencer_time;
unsigned int sequencer_playhead_prev, sequencer_playhead;


void sequencer_init() {
	rgb_led(99, mode_sequencer_r, mode_sequencer_g, mode_sequencer_b); // Note mode LED
	active_port = USBSTANDALONE;

	sequencer_bpm = 120;
	sequencer_time = 0;

	sequencer_playhead_prev = 0;
	sequencer_playhead = 0;
}

void sequencer_tick() {
	rgb_led(SEQUENCER_PLAYHEAD_LED(sequencer_playhead_prev), 0, 0, 0);
	rgb_led(SEQUENCER_PLAYHEAD_LED(sequencer_playhead), MAXLED, MAXLED, MAXLED);

	sequencer_playhead_prev = sequencer_playhead;
}

void sequencer_timer_event() {
	// update time
	sequencer_time++;
	if (sequencer_time >= 128) {
		sequencer_time = 0;

		// update playhead
		sequencer_playhead++;
		if (sequencer_playhead >= 16) {
			sequencer_playhead = 0;
		}

		sequencer_tick();
	}
}

void sequencer_surface_event(u8 p, u8 v, u8 x, u8 y) {
	// enter Setup mode
	if (p == 0 && v != 0) {
		mode_update(mode_setup);
		return;
	}
}

void sequencer_midi_event(u8 port, u8 t, u8 ch, u8 p, u8 v) {}

void sequencer_aftertouch_event(u8 v) {}

void sequencer_poly_event(u8 p, u8 v) {}

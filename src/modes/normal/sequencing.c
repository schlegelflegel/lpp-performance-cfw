#include "modes/normal/sequencing.h"

#include "sequencer/sequencer.h"


#define SEQUENCING_PLAYHEAD_LED(pos) (81 + (pos) - 18 * ((pos) >> 3))


static struct sequencer seq;


void sequencing_init() {
	// note mode LED
	rgb_led(99, mode_sequencing_r, mode_sequencing_g, mode_sequencing_b);
	active_port = USBSTANDALONE;

	sequencer_init(&seq);
}

void sequencing_timer_event() {
	sequencer_update(&seq);

	// clear playhead area
	for (unsigned int i = 71; i <= 78; i++) rgb_led(i, 15, 15, 15);
	for (unsigned int i = 81; i <= 88; i++) rgb_led(i, 15, 15, 15);

	// set playhead color
	rgb_led(SEQUENCING_PLAYHEAD_LED(seq.ph.sixteenth), 0, 63, 15);
}

void sequencing_surface_event(u8 p, u8 v, u8 x, u8 y) {
	// enter Setup mode
	if (p == 0 && v != 0) {
		mode_update(mode_setup);
		return;
	}
}

void sequencing_midi_event(u8 port, u8 t, u8 ch, u8 p, u8 v) {}

void sequencing_aftertouch_event(u8 v) {}

void sequencing_poly_event(u8 p, u8 v) {}

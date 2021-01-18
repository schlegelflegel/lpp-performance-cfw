#include "modes/normal/sequencing.h"

#include "sequencer/sequencer.h"


#define SEQUENCING_


static const u8 keyboard_layout[] = { 1, 12, 2, 13, 3, 4, 15, 5, 16, 6, 17, 7, 8 };


static void sequencer_redraw() {
	unsigned int x, y, pos, led;

	for (y = 0; y < 4; y++) {
		for (x = 0; x < 8; x++) {
			pos = y * 8 + x;
			led = 81 - 10 * y + x;

			if (pos == sequencer.playhead.position) {
				rgb_led(led, 0, 63, 0);
			} else if (pos % 4 == 0) {
				rgb_led(led, 15, 15, 15);
			} else {
				rgb_led(led, 0, 0, 0);
			}
		}
	}
}

void sequencing_init() {
	sequencer_redraw_callback = sequencer_redraw;

	sequencer_play();
}

void sequencing_timer_event() {
}

void sequencing_surface_event(u8 p, u8 v, u8 x, u8 y) {
}

void sequencing_midi_event(u8 port, u8 t, u8 ch, u8 p, u8 v) {}

void sequencing_aftertouch_event(u8 v) {}

void sequencing_poly_event(u8 p, u8 v) {}

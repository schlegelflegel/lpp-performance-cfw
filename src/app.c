
#include "app.h"

#define MAX 0x20000
#define SINGLE 16
#define SPEED 8

u32 global_timer = 0;
u8 started = 0;

u8 send_buf[SINGLE * 2 + 2] = {0xF0};

void app_timer_event() {
	if (!started) return;
	
	if (global_timer++ % (SINGLE * SPEED) == 0) {
		for (u32 i = 0; i < SINGLE; i++) {
			u8 val = *(u8*)(0x08000000 + global_timer / SPEED + i);
			send_buf[i * 2 + 1] = val >> 4;
			send_buf[i * 2 + 2] = val & 0x0F;
		}
		
		hal_send_sysex(USBMIDI, &send_buf[0], SINGLE * 2 + 2);

		for (u8 i = 0; i <= global_timer / SPEED * SINGLE / MAX; i++) {
			hal_plot_led(TYPEPAD, (i / 8 + 1) * 10 + (i % 8 + 1), 63, 63, 63);
		}

		if (global_timer / SPEED >= MAX) {
			global_timer = 0;
			started = 0;
		}
	}
}

void app_surface_event(u8 t, u8 p, u8 v) {
	started = 1;
}

void app_midi_event(u8 port, u8 t, u8 p, u8 v) {}

void app_aftertouch_event(u8 p, u8 v) {}

void app_cable_event(u8 t, u8 v) {}

void app_sysex_event(u8 port, u8 *d, u16 l) {}

void app_init(const u16 *adc_raw) {
	send_buf[SINGLE * 2 + 1] = 0xF7;
}
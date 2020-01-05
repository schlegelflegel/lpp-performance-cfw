
#include "app.h"

void app_timer_event() {}

void app_surface_event(u8 t, u8 p, u8 v) {
	hal_plot_led(TYPEPAD, 11, 63, 63, 63);

	// This is just an attempt which doesn't work. FW will poweroff here. Remove writes to not poweroff.
	*(u8*)0x08005158 = '#';
	*(u8*)0x08005159 = 'H';
	*(u8*)0x0800515A = 'a';
	*(u8*)0x0800515B = 'c';
	*(u8*)0x0800515C = 'k';
	*(u8*)0x0800515D = 'i';
	*(u8*)0x0800515E = 'n';
	*(u8*)0x0800515F = 'g';

	hal_plot_led(TYPEPAD, 12, 63, 63, 63);

	u8 buf[10] = {0xF0};
	buf[9] = 0xF7;

	for (int i = 0; i < 8; i++) {
		buf[i + 1] = *(u8*)(0x08005158 + i);
	}

	hal_plot_led(TYPEPAD, 13, 63, 63, 63);

	hal_send_sysex(USBMIDI, &buf[0], 10);

	hal_plot_led(TYPEPAD, 14, 63, 63, 63);
}

void app_midi_event(u8 port, u8 t, u8 p, u8 v) {}

void app_aftertouch_event(u8 p, u8 v) {}

void app_cable_event(u8 t, u8 v) {}

void app_sysex_event(u8 port, u8 *d, u16 l) {}

void app_init(const u16 *adc_raw) {
	hal_plot_led(TYPEPAD, 10, 63, 63, 63);
}
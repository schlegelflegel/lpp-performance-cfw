#ifndef APP_H
#define APP_H

#include "app_defs.h"

u32 global_timer;
u8 active_port;

void hal_plot_led(u8 type, u8 index, u8 red, u8 green, u8 blue);
void hal_send_midi(u8 port, u8 status, u8 data1, u8 data2);
void hal_send_sysex(u8 port, const u8* data, u16 length);
void hal_read_flash(u32 offset, u8 *data, u32 length);
void hal_write_flash(u32 offset,const u8 *data, u32 length);

void app_timer_event();
void app_surface_event(u8 type, u8 index, u8 value);
void app_midi_event(u8 port, u8 status, u8 d1, u8 d2);
void app_aftertouch_event(u8 index, u8 value);
void app_cable_event(u8 type, u8 value);
void app_sysex_event(u8 port, u8 * data, u16 count);

void app_init(const u16 *adc_buffer);

#endif
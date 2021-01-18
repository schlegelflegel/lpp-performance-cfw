#ifndef LED_H
#define LED_H

#include "app.h"

#include "modes/mode.h"
#include "led/palettes.h"
#include "flash/settings.h"

#define split_rgb(arr) (arr)[0], (arr)[1], (arr)[2]
#define split_rgb_darker(arr) (arr)[0] >> 2, (arr)[1] >> 2, (arr)[2] >> 2

u8 flash_screen[100][3], pulse_screen[100][3];

void direct_led(u8 p, u8 r, u8 g, u8 b);
void rgb_led(u8 p, u8 r, u8 g, u8 b);
void clear_led();
void palette_led(u8 p, u8 v);
void novation_led(u8 p, u8 v);

void flash_led(u8 p, u8 v);
void flash_rgb_led(u8 p, u8 r, u8 g, u8 b);
void pulse_led(u8 p, u8 v);
void pulse_rgb_led(u8 p, u8 r, u8 g, u8 b);

void display_u8(u8 v, u8 d, u8 x, u8 r, u8 g, u8 b);
void display_u6(u8 v, u8 d, u8 x, u8 r, u8 g, u8 b);

#endif
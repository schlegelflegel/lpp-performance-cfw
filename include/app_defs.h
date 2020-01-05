#ifndef APP_DEFS_H
#define APP_DEFS_H

typedef signed long  s32;
typedef signed short s16;
typedef signed char  s8;

typedef unsigned long  u32;
typedef unsigned short u16;
typedef unsigned char  u8;

#define	TYPEPAD				0
#define	TYPESETUP			1

#define	MAXLED				63

#define	NOTEON				0x90
#define	NOTEOFF				0x80
#define	POLYAFTERTOUCH		0xA0
#define	CC					0xB0
#define	CHANNELAFTERTOUCH   0xD0
#define	SONGPOSITIONPOINTER 0xF2
#define	MIDITIMINGCLOCK     0xF8
#define	MIDISTART           0xFA
#define	MIDICONTINUE        0xFB
#define	MIDISTOP            0xFC

#define	USBSTANDALONE		0
#define	USBMIDI				1
#define	DINMIDI				2

#define	MIDI_IN_CABLE		0
#define	MIDI_OUT_CABLE		1

#define USER_AREA_SIZE 1024

#define PAD_COUNT 64

static const u8 ADC_MAP[PAD_COUNT] =
{
	11, 51, 12, 52, 13, 53, 14, 54,
	15, 55, 16, 56, 17 ,57, 18, 58,
	21, 61, 22, 62, 23, 63, 24, 64,
	25, 65, 26, 66, 27, 67, 28, 68,
	31, 71, 32, 72, 33, 73, 34, 74,
	35, 75, 36, 76, 37, 77, 38, 78,
	41, 81, 42, 82, 43, 83, 44, 84,
	45, 85, 46, 86, 47, 87, 48, 88,
};

#endif
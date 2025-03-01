#include "led/palettes.h"

u8 palette[palette_custom][3][128] = {
	{ // User-defined flash-backed palette 1
		{0},
		{0},
		{0}
	},
	{ // User-defined flash-backed palette 2
		{0},
		{0},
		{0}
	},
	{ // User-defined flash-backed palette 3
		{0},
		{0},
		{0}
	}
};

const u8 palette_preset[palette_count - palette_custom - 1][3][128] = {
	{ // Novation's default palette
		{0, 16, 32, 63, 63, 63, 32, 16, 63, 63, 32, 16, 63, 63, 32, 16, 33, 20, 10, 5, 18, 0, 0, 0, 18, 0, 0, 0, 18, 0, 0, 0, 18, 0, 0, 0, 18, 0, 0, 0, 18, 0, 0, 0, 11, 0, 0, 0, 26, 11, 6, 3, 63, 63, 32, 16, 63, 63, 32, 16, 63, 37, 29, 8, 0, 0, 0, 0, 0, 4, 31, 7, 63, 46, 43, 24, 3, 0, 0, 0, 6, 22, 43, 10, 63, 33, 28, 0, 14, 21, 13, 22, 12, 26, 52, 63, 63, 45, 35, 32, 14, 0, 3, 5, 5, 25, 32, 54, 53, 63, 39, 25, 5, 54, 31, 38, 35, 15, 28, 55, 39, 13, 6, 1, 45, 15, 44, 18},
		{0, 16, 32, 63, 15, 0, 0, 0, 46, 15, 8, 4, 43, 63, 32, 16, 63, 63, 32, 16, 63, 63, 32, 16, 63, 63, 32, 16, 63, 63, 32, 16, 63, 63, 32, 16, 48, 41, 21, 11, 33, 21, 11, 6, 9, 0, 0, 0, 13, 0, 0, 0, 15, 0, 0, 0, 16, 0, 0, 0, 3, 13, 20, 13, 14, 18, 5, 0, 17, 0, 31, 7, 0, 63, 58, 63, 34, 63, 41, 10, 0, 0, 6, 4, 12, 55, 63, 63, 63, 63, 63, 34, 20, 20, 7, 0, 17, 41, 63, 22, 10, 18, 19, 5, 7, 14, 0, 16, 18, 47, 55, 44, 5, 52, 58, 37, 25, 15, 28, 63, 0, 0, 51, 16, 43, 12, 20, 5},
		{0, 16, 32, 63, 15, 0, 0, 0, 26, 0, 0, 0, 11, 0, 0, 0, 12, 0, 0, 0, 18, 0, 0, 0, 23, 6, 3, 1, 22, 21, 11, 6, 45, 37, 18, 9, 63, 63, 32, 16, 63, 63, 32, 16, 63, 63, 32, 16, 62, 63, 32, 16, 63, 63, 32, 16, 27, 20, 10, 5, 0, 0, 0, 1, 0, 6, 27, 63, 19, 50, 31, 7, 0, 11, 1, 2, 0, 23, 63, 63, 63, 63, 30, 0, 0, 1, 5, 0, 9, 27, 50, 63, 48, 57, 63, 22, 0, 0, 0, 1, 0, 3, 8, 10, 22, 6, 0, 10, 4, 9, 11, 3, 11, 26, 34, 63, 63, 15, 28, 63, 0, 0, 0, 0, 0, 0, 0, 0}
	},
	{ // mat1jaczyyy's custom palette
		{0, 15, 31, 47, 63, 63, 15, 31, 47, 63, 63, 15, 31, 47, 63, 63, 15, 31, 47, 63, 63, 15, 31, 47, 63, 63, 11, 23, 35, 51, 47, 7, 15, 23, 39, 31, 3, 7, 11, 27, 15, 0, 0, 0, 15, 0, 0, 0, 0, 15, 0, 0, 0, 0, 15, 0, 0, 0, 0, 15, 0, 0, 0, 0, 15, 0, 0, 0, 0, 15, 0, 0, 0, 0, 15, 0, 0, 0, 0, 15, 0, 0, 0, 0, 15, 0, 3, 7, 11, 27, 15, 7, 15, 23, 39, 31, 11, 23, 35, 51, 47, 15, 31, 47, 62, 63, 15, 31, 47, 63, 63, 15, 31, 47, 63, 63, 15, 31, 47, 63, 63, 9, 18, 27, 36, 45, 54, 63},
		{0, 0, 0, 0, 15, 0, 3, 7, 11, 27, 15, 7, 15, 23, 39, 31, 11, 23, 35, 51, 47, 15, 31, 47, 63, 63, 15, 31, 47, 63, 63, 15, 31, 47, 63, 63, 15, 31, 47, 63, 63, 15, 31, 47, 63, 63, 15, 31, 47, 63, 63, 15, 31, 47, 63, 63, 15, 31, 47, 63, 63, 15, 31, 47, 62, 63, 11, 23, 35, 51, 47, 7, 15, 23, 39, 31, 3, 7, 11, 27, 15, 0, 0, 0, 15, 0, 0, 0, 0, 15, 0, 0, 0, 0, 15, 0, 0, 0, 0, 15, 0, 0, 0, 0, 15, 0, 0, 0, 0, 15, 0, 0, 0, 0, 15, 0, 0, 0, 0, 15, 0, 9, 18, 27, 36, 45, 54, 63},
		{0, 0, 0, 0, 15, 0, 0, 0, 0, 15, 0, 0, 0, 0, 15, 0, 0, 0, 0, 15, 0, 0, 0, 0, 15, 0, 0, 0, 0, 15, 0, 0, 0, 0, 15, 0, 0, 0, 0, 15, 0, 0, 0, 0, 15, 0, 3, 7, 11, 27, 15, 7, 15, 23, 39, 31, 11, 23, 35, 51, 47, 15, 31, 47, 63, 63, 15, 31, 47, 63, 63, 15, 31, 47, 63, 63, 15, 31, 47, 63, 63, 15, 31, 47, 63, 63, 15, 31, 47, 63, 63, 15, 31, 47, 63, 63, 15, 31, 47, 63, 63, 15, 31, 47, 62, 63, 11, 23, 35, 51, 47, 7, 15, 23, 39, 31, 3, 7, 11, 27, 15, 9, 18, 27, 36, 45, 54, 63}
	}
	// Launchpad S legacy palette is calculated
};

u8 palette_value(u8 i, u8 v, u8 c) {
	if (i < palette_custom) return palette[i][c][v];

	if (i == 5) { // Launchpad S Palette
		if (c == 0) return v % 4 * 21;
		if (c == 1) return (v / 16) % 4 * 21;
		return 0;
	}

	return palette_preset[i - palette_custom][c][v];
}
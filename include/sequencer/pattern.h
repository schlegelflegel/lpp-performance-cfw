#ifndef PATTERN_H
#define PATTERN_H


#define PATTERN_LENGTH_MIN 1
#define PATTERN_LENGTH_MAX 32

#define NOTE_PATTERN_POLYPHONY 3
#define DRUM_PATTERN_SAMPLES 8


typedef struct note_pattern_single_step {
    unsigned char note;
    unsigned char vel;
} note_pattern_single_step_t;

typedef note_pattern_single_step_t note_pattern_step_t[NOTE_PATTERN_POLYPHONY];
typedef unsigned char drum_pattern_step_t[DRUM_PATTERN_SAMPLES / sizeof(unsigned char)];

typedef struct drum_pattern {
    drum_pattern_step_t *steps;
    unsigned int length;
} drum_pattern_t;

typedef struct note_pattern {
    note_pattern_step_t *steps;
    unsigned int length;
} note_pattern_t;


#endif

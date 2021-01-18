#ifndef PLAYHEAD_H
#define PLAYHEAD_H


typedef struct playhead {
    unsigned int clock;
    unsigned int position;
    unsigned int bars;
} playhead_t;


void playhead_init(playhead_t *ph);

void playhead_pulse(playhead_t *ph, unsigned int position_length);
void playhead_reset(playhead_t *ph);
void playhead_set(playhead_t *ph, unsigned int clock);


#endif

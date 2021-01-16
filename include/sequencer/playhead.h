#ifndef PLAYHEAD_H
#define PLAYHEAD_H


struct playhead {
    unsigned int position;
    unsigned int thirtysecond;
    unsigned int sixteenth;
    unsigned int eighth;
    unsigned int quarter;
    unsigned int half;
    unsigned int whole;
    unsigned int bars;
};


void playhead_init(struct playhead *ph);

void playhead_pulse(struct playhead *ph, unsigned int position_length);
void playhead_reset(struct playhead *ph);
void playhead_set(struct playhead *ph, unsigned int clock);


#endif

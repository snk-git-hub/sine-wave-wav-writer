#ifndef TONE_H
#define TONE_H

#include <stdint.h>
#include <stddef.h>

#define AMPLITUDE (0.7 * 32767)

/* Fill buf with `count` samples of a sine wave.
 * start_index is the global index of buf[0], so blocks join without a gap. */
void tone_generate_block(int16_t *buf, size_t count, size_t start_index, double freq_hz);

#endif

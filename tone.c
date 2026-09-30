#include <math.h>
#include "tone.h"
#include "wav.h"

void tone_generate_block(int16_t *buf, size_t count, size_t start_index, double freq_hz)
{
    /* TODO: for i in [0, count):
     *         n = start_index + i
     *         value = AMPLITUDE * sin(2 * M_PI * freq_hz * n / SAMPLE_RATE)
     *         buf[i] = (int16_t)value
     */
    (void)buf;
    (void)count;
    (void)start_index;
    (void)freq_hz;
}

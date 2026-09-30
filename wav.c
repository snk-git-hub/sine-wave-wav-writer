#include <string.h>
#include "wav.h"

int wav_write_header(FILE *fp, uint32_t num_samples)
{
    struct wav_header h;

    /* TODO: copy the four-character tags ("RIFF", "WAVE", "fmt ", "data")
     *       with memcpy (they are not NUL-terminated).
     * TODO: compute data_size = num_samples * (BITS_PER_SAMPLE / 8).
     * TODO: fill every field using the layout table in the README.
     * TODO: fwrite(&h, sizeof h, 1, fp) and check the return value. */
    (void)fp;
    (void)num_samples;
    (void)h;

    return -1;
}

int wav_write_samples(FILE *fp, const int16_t *samples, size_t count)
{
    /* TODO: fwrite the samples and confirm the number written equals count. */
    (void)fp;
    (void)samples;
    (void)count;

    return -1;
}

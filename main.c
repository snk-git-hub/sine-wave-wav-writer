#include <stdio.h>
#include <stdlib.h>
#include "wav.h"
#include "tone.h"

#define BLOCK_SIZE 1024

static void print_usage(const char *prog)
{
    fprintf(stderr, "Usage: %s <frequency_hz> <duration_s> <output.wav>\n", prog);
}

/* Parse and validate arguments. Returns 0 on success, -1 on failure.
 * Ranges: frequency 20..20000 Hz, duration 1..10 s. */
static int parse_args(int argc, char *argv[], double *freq, int *duration, const char **path)
{
    /* TODO: check argc == 4.
     * TODO: convert with strtod / strtol and check for conversion errors.
     * TODO: check the ranges and set the outputs. */
    (void)argc;
    (void)argv;
    (void)freq;
    (void)duration;
    (void)path;

    return -1;
}

int main(int argc, char *argv[])
{
    double freq;
    int duration;
    const char *path;

    if (parse_args(argc, argv, &freq, &duration, &path) != 0) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    uint32_t total_samples = (uint32_t)SAMPLE_RATE * (uint32_t)duration;
    (void)total_samples;
    (void)freq;

    FILE *fp = fopen(path, "wb");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    /* TODO: write the header with wav_write_header.
     * TODO: loop in blocks of BLOCK_SIZE until total_samples are written:
     *         - work out this block's count (the last block may be shorter)
     *         - tone_generate_block(...)
     *         - wav_write_samples(...)
     * TODO: fclose and check its return value.
     * TODO: print: Samples, Data size, File size. */

    fclose(fp);
    return EXIT_SUCCESS;
}

#ifndef WAV_H
#define WAV_H

#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

#define SAMPLE_RATE      44100
#define NUM_CHANNELS     1
#define BITS_PER_SAMPLE  16

/* 44-byte WAV header. Field order and sizes must match the file layout exactly. */
struct __attribute__((packed)) wav_header {
    char     chunk_id[4];       /* "RIFF" */
    uint32_t chunk_size;        /* 36 + data_size */
    char     format[4];         /* "WAVE" */
    char     subchunk1_id[4];   /* "fmt " */
    uint32_t subchunk1_size;    /* 16 */
    uint16_t audio_format;      /* 1 = PCM */
    uint16_t num_channels;
    uint32_t sample_rate;
    uint32_t byte_rate;
    uint16_t block_align;
    uint16_t bits_per_sample;
    char     subchunk2_id[4];   /* "data" */
    uint32_t subchunk2_size;    /* num_samples * 2 */
};

/* Fill in and write the header. Returns 0 on success, -1 on failure. */
int wav_write_header(FILE *fp, uint32_t num_samples);

/* Write `count` samples. Returns 0 on success, -1 on failure. */
int wav_write_samples(FILE *fp, const int16_t *samples, size_t count);

#endif

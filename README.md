# sine-wave-wav-writer

A command-line program written in C that generates a sine-wave tone and saves it as a playable **WAV** file (mono, 16-bit PCM, 44100 Hz).

Built as a practice project on sampling, fixed-width integer types, binary file formats and file I/O.
<img width="1692" height="967" alt="Screenshot 2026-10-01 010701" src="https://github.com/user-attachments/assets/a038b8d3-bf25-4272-b8f4-67341bb9056e" />

## Features

- Generates a pure sine tone at any frequency from 20 to 20000 Hz
- Duration of 1 to 10 seconds
- Writes a valid 44-byte WAV header (little-endian) followed by 16-bit PCM samples
- Validates command-line arguments and checks every file operation
- Writes samples in blocks for efficient I/O

## How it works

1. The number of samples is `N = sample_rate × duration`.
2. Each sample is computed as:

   ```
   sample[n] = (int16_t)(amplitude * sin(2π · f · n / sample_rate))
   ```

   with `amplitude = 0.7 * 32767` to avoid clipping.
3. A WAV header is written first, then the samples.

### WAV header layout

| Offset | Size | Field | Value |
|---|---|---|---|
| 0 | 4 | ChunkID | `"RIFF"` |
| 4 | 4 | ChunkSize | `36 + data_size` |
| 8 | 4 | Format | `"WAVE"` |
| 12 | 4 | Subchunk1ID | `"fmt "` |
| 16 | 4 | Subchunk1Size | 16 |
| 20 | 2 | AudioFormat | 1 (PCM) |
| 22 | 2 | NumChannels | 1 |
| 24 | 4 | SampleRate | 44100 |
| 28 | 4 | ByteRate | `sample_rate × channels × 2` |
| 32 | 2 | BlockAlign | `channels × 2` |
| 34 | 2 | BitsPerSample | 16 |
| 36 | 4 | Subchunk2ID | `"data"` |
| 40 | 4 | Subchunk2Size | `N × 2` |

## Build

Requires `gcc` and the math library.

```bash
gcc -Wall -Wextra -o tone main.c -lm
```

## Usage

```bash
./tone <frequency_hz> <duration_s> <output.wav>
```

Example:

```bash
$ ./tone 440 2 a440.wav
Samples: 88200
Data size: 176400 bytes
File size: 176444 bytes
```

A 440 Hz tone is the musical note A4. Open `a440.wav` in any media player to check it.

## Project structure

```
c-wav-tone-generator/
├── main.c        # argument parsing, sample generation, file output
├── README.md
└── .gitignore    # ignore the binary and generated .wav files
```

## Concepts practised

- `<stdint.h>` fixed-width types (`int16_t`, `uint16_t`, `uint32_t`)
- Struct layout, padding and packing for file headers
- Little-endian byte order
- `fopen`, `fwrite`, `fclose` and error checking
- Converting floating-point math results to integer samples
- Command-line arguments (`argc`, `argv`)

## Possible extensions

- Fade-in and fade-out (for example 50 ms) to remove clicks
- Play a short melody by writing several notes into one file
- Other waveforms: square, triangle, sawtooth
- Stereo output

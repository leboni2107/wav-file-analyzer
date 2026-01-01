#ifndef LIBRARY_H
#define LIBRARY_H
#pragma once

#include <cstdint>
#include <string>

/**
 * @param riff        Byte 1 - 4   "RIFF"                  Marks the file as a riff file. Characters are each 1 byte long.
 * @param fsize       Byte 5 - 8   File size (integer)     Size of the overall file - 8 bytes, in bytes (32-bit integer). Typically, you'd fill this in after creation.
 * @param wave        Byte 9 -12   "WAVE"                  File Type Header. For our purposes, it always equals "WAVE".
 * @param fmt         Byte 13-16   "fmt "                  Format chunk marker. Includes trailing null
 * @param fmtlength   Byte 17-20   16                      Length of format data as listed above
 * @param type        Byte 21-22   1                       Type of format (1 is PCM) - 2 byte integer
 * @param numchannels Byte 23-24   2                       Number of Channels - 2 byte integer
 * @param samplerate  Byte 25-28   44100                   Sample Rate - 32 byte integer. Common values are 44100 (CD), 48000 (DAT). Sample Rate = Number of Samples per second, or Hertz.
 * @param sbc         Byte 29-32   176400                  (Sample Rate * BitsPerSample * Channels) / 8.
 * @param bpsc        Byte 33-34   4                       (BitsPerSample * Channels) / 8.1 - 8 bit mono2 - 8 bit stereo/16 bit mono4 - 16 bit stereo
 * @param bps         Byte 35-36   16                      Bits per sample
 * @param data        Byte 37-40   "data"                  "data" chunk header. Marks the beginning of the data section.
 * @param dsize       Byte 41-44   File size (data)        Size of the data section.
 */
struct Header {
    char riff[5];
    int32_t fsize;
    char wave[5];
    char fmt[5];
    int32_t fmtlength;
    short type;
    short numchannels;
    int32_t samplerate;
    int32_t sbc;
    short bpsc;
    short bps;
    char data[5];
    int32_t dsize;
};

/**
 * @param path path to .wav file to be parsed
 * @return .wav file parsed into header structure
 */
Header parse(std::string path);

/**
 * @param header Header to be printed
 * @return no return value
 */
int output(Header header);

/**
 * @return Initialized Header into RIFF PCM format, without: fsize, numchannels, samplerate, sbc, bpsc, bps, dsize
 */
Header initializeHeader();

#endif //WAV-FILE-ANALYZER_LIBRARY_H
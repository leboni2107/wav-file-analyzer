| Struct Header | Byte | Example Value | Description |
| ----------- | ----------- | ----------- |  ----------- |
| riff | 1-4 | "RIFF" | Marks the file as a riff file. Characters are each 1 byte long. |
| fsize | 5-8 | File Size (integer) | Size of the overall file - 8 bytes, in bytes (32-bit integer). Typically, you'd fill this in after creation. |
| wave | 9-12 | "WAVE" | File Type Header. For our purposes, it always equals "WAVE". |
| fmt | 13-16 | "fmt " | Format chunk marker. Includes trailing null |


| Function | Description | Parameters |
| ----------- | ----------- | ----------- |
| parse | parses a .wav file into a Header struct | string path: path to the .wav file to be parsed |
| output | Prints a Header struct | Header header: Header to be printed |
| initializeHeader | Initializes fields riff, wave, fmt, data | |

#include <iostream>
#include <fstream>
#include <filesystem>
#include "library.h"

using namespace std;

int memcopy(char* dest, const char* src, int size, int offset) {
    for (int i = offset; i < size+offset; i++) {
        dest[i-offset] = src[i];
    }
    return 0;
}

Header formatHeader(char buffer[]) {
    Header response;

    memcopy(response.riff, buffer, 4, 0); response.riff[4] = '\0';
    memcopy((char*)&response.fsize, buffer, 4, 4);
    memcopy(response.wave, buffer, 4, 8); response.wave[4] = '\0';
    memcopy(response.fmt, buffer, 4, 12); response.fmt[4] = '\0';
    memcopy((char*)&response.fmtlength, buffer, 4, 16);
    memcopy((char*)&response.type, buffer, 2, 20);
    memcopy((char*)&response.numchannels, buffer, 2, 22);
    memcopy((char*)&response.samplerate, buffer, 4, 24);
    memcopy((char*)&response.sbc, buffer, 4, 28);
    memcopy((char*)&response.bpsc, buffer, 2, 32);
    memcopy((char*)&response.bps, buffer, 2, 34);
    memcopy(response.data, buffer, 4, 36); response.data[4] = '\0';
    memcopy((char*)&response.dsize, buffer, 4, 40);
    return response;
}

int output(Header header) {
    cout << "| Riff:          " << header.riff << endl;
    cout << "| Filesize:      " << header.fsize << endl;
    cout << "| Wave:          " << header.wave << endl;
    cout << "| Format:        " << header.fmt << endl;
    cout << "| Format length: " << header.fmtlength << endl;
    cout << "| Type:          " << header.type << endl;
    cout << "| Num channels:  " << header.numchannels << endl;
    cout << "| Samplerate:    " << header.samplerate << endl;
    cout << "| SBC:           " << header.sbc << endl;
    cout << "| BPSC:          " << header.bpsc << endl;
    cout << "| BPS:           " << header.bps << endl;
    cout << "| Data:          " << header.data << endl;
    cout << "| Data size:     " << header.dsize << endl;
    return 0;
}

Header parse(string path) {
    ifstream file;
    char buffer[44];
    string selection;
    Header header;

    try {
        file.open(path, ios::binary);

        file.read(buffer ,44);
        file.close();

        header = formatHeader(buffer);
        output(header);
        return header;
    }
    catch (exception &e) {
        cout << e.what() << endl;
        return Header{};
    }
}
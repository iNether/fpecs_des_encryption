#include "fileencryption.h"
#include <chrono>

FileEncryption::FileEncryption(ui64 key) :
    des(key, (ui64)0x0000000000000000)
{
}

int FileEncryption::encrypt(string input, string output)
{
    return crypt(input, output, false);
}
int FileEncryption::decrypt(string input, string output)
{
    return crypt(input, output, true);
}

// MODE false    for encrypt
// MODE true     for decrypt
int FileEncryption::crypt(string input, string output, bool mode)
{
    auto start = chrono::steady_clock::now(); // chrono START pos
    
    ifstream ifile;
    ofstream ofile;
    ui64 buffer;

    if (input.length() < 1) input = "/dev/stdin";
    if (output.length() < 1) output = "/dev/stdout";

    ifile.open(input, ios::binary | ios::in | ios::ate);
    ofile.open(output, ios::binary | ios::out);

    ui64 size = ifile.tellg();
    ifile.seekg(0, ios::beg);

    ui64 block = size / 8;
    if (mode) block--;

    

    for (ui64 i = 0; i < block; i++)
    {
        ifile.read((char*)&buffer, 8);

        if (mode)
            buffer = des.decrypt(buffer);
        else
            buffer = des.encrypt(buffer);

        ofile.write((char*)&buffer, 8);
    }

    if (mode == false)      // Encrypt
    {
        // Needed amount of Padding
        ui8 padding = 8 - (size % 8);

        // Exception. Padding cannot be 0 -> pad full block
        if (padding == 0)
            padding = 8;

        // Read remaining part of File
        buffer = (ui64)0;
        if (padding != 8)
            ifile.read((char*)&buffer, 8 - padding);

        // Pad block with a 1 followed by 0s
        ui8 shift = padding * 8;
        buffer <<= shift;
        buffer |= (ui64)0x0000000000000001 << (shift - 1);

        buffer = des.encrypt(buffer);
        ofile.write((char*)&buffer, 8);
    }
    else        // Decrypt
    {
        // Read last line of File
        ifile.read((char*)&buffer, 8);
        buffer = des.decrypt(buffer);

        // Amount of padding
        ui8 padding = 0;

        // Check for and record Padding on end
        while (!(buffer & 0x00000000000000ff))
        {
            buffer >>= 8;
            padding++;
        }

        buffer >>= 8;
        padding++;

        if (padding != 8)
            ofile.write((char*)&buffer, 8 - padding);
    }

    ifile.close();
    ofile.close();

    auto timeMillis = std::chrono::duration_cast<std::chrono::milliseconds>(chrono::steady_clock::now() - start);
    return timeMillis.count();
}

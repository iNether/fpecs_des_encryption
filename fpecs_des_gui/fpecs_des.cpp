#include "fpecs_des.h"
#include <iostream>
#include "fileencryption.h"
using namespace std;
#include <chrono>
#include <windows.h>

//void usage()
//{
//    cout << "Usage: cppDES -e/-d key [input-file] [output-file]" << endl;
//}

//int main_des(int argc, char** argv)
//{
//    auto start = chrono::steady_clock::now();
//
//    // ERROR 1
//    if (argc < 3)
//    {
//        //usage();
//        //cout << "Wrong number of args.    3 is needed" << endl;
//        return 0101;
//    }
//
//    // ERROR 2
//    string enc_dec = argv[1];
//    if (enc_dec != "-e" && enc_dec != "-d")
//    {
//        //usage();
//        //cout << "Wrong mode.\n" << " -e for encryp\n -d for decrypt" << endl;
//        return 0202;
//    }
//
//    // define   i/o PATH
//    string input, output;
//    if (argc > 3)
//        input = argv[3];
//    if (argc > 4)
//        output = argv[4];
//
//    // define   KEY
//    ui64 key = strtoull(argv[2], nullptr, 16);
//    FileEncryption fe(key);
//
//    // Encryption
//    if (enc_dec == "-e")
//        return fe.encrypt(input, output);
//
//    // Decryption
//    if (enc_dec == "-d")
//        return fe.decrypt(input, output);
//
//    auto end = chrono::steady_clock::now();
//    cout << "Completed in " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;
//    return 0;
//}


int main_des_gui(string mode, char* ekey ,string ipath, string opath)
{

    string enc_dec = mode;
    // define   i/o PATH
    string input, output;
    input = ipath;
    output = opath;

    // define   KEY
    ui64 key = strtoull(ekey, nullptr, 16);
    FileEncryption fe(key);

    // Encryption
    if (enc_dec == "-e")
        return fe.encrypt(input, output);

    // Decryption
    if (enc_dec == "-d")
        return fe.decrypt(input, output);

    return -1;
}

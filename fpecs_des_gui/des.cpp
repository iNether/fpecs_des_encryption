#include "des.h"
#include "des_key.h"
#include "des_data.h"

DES::DES(ui64 key)
{
    keygen(key);
}

ui64 DES::encrypt(ui64 block)
{
    return des(block, false);
}

ui64 DES::decrypt(ui64 block)
{
    return des(block, true);
}

ui64 DES::encrypt(ui64 block, ui64 key)
{
    DES des(key);
    return des.des(block, false);
}

ui64 DES::decrypt(ui64 block, ui64 key)
{
    DES des(key);
    return des.des(block, true);
}

void DES::keygen(ui64 key)
{
    // initial Key schedule calculation
    ui64 permuted_choice_1 = 0; // 56 bits
    for (ui8 i = 0; i < 56; i++)
    {
        permuted_choice_1 <<= 1;
        permuted_choice_1 |= (key >> (64 - PC1[i])) & LB64_MASK;
    }

    // 28 bits
    ui32 C = (ui32)((permuted_choice_1 >> 28) & 0x000000000fffffff);
    ui32 D = (ui32)(permuted_choice_1 & 0x000000000fffffff);

    // calculate 16 Keys
    for (ui8 i = 0; i < 16; i++)
    {
        // key schedule, shift Ci with Di
        for (ui8 j = 0; j < ITERATION_SHIFT[i]; j++)
        {
            C = (0x0fffffff & (C << 1)) | (0x00000001 & (C >> 27));
            D = (0x0fffffff & (D << 1)) | (0x00000001 & (D >> 27));
        }

        ui64 permuted_choice_2 = (((ui64)C) << 28) | (ui64)D;

        sub_key[i] = 0; // 48 bits (2*24)
        for (ui8 j = 0; j < 48; j++)
        {
            sub_key[i] <<= 1;
            sub_key[i] |= (permuted_choice_2 >> (56 - PC2[j])) & LB64_MASK;
        }
    }
}

ui64 DES::des(ui64 block, bool mode)
{
    // apply initial permutation
    block = ip(block);

    // divide T' for two 32bit parts
    ui32 L = (ui32)(block >> 32) & L64_MASK;
    ui32 R = (ui32)(block & L64_MASK);

    // 16 rounds
    for (ui8 i = 0; i < 16; i++)
    {
        ui32 F = mode ? f(R, sub_key[15 - i]) : f(R, sub_key[i]);
        feistel(L, R, F);
    }

    // swap the two parts
    block = (((ui64)R) << 32) | (ui64)L;
    
    // apply final permutation
    return fp(block);
}

// initial permutation
ui64 DES::ip(ui64 block)
{
    ui64 result = 0;
    for (ui8 i = 0; i < 64; i++)
    {
        result <<= 1;
        result |= (block >> (64 - IP[i])) & LB64_MASK;
    }
    return result;
}

// inverse initial permutation
ui64 DES::fp(ui64 block)
{
    ui64 result = 0;
    for (ui8 i = 0; i < 64; i++)
    {
        result <<= 1;
        result |= (block >> (64 - FP[i])) & LB64_MASK;
    }
    return result;
}

// feistel cypher structure
void DES::feistel(ui32& L, ui32& R, ui32 F)
{
    ui32 temp = R;
    R = L ^ F;
    L = temp;
}

// f(R,k)
ui32 DES::f(ui32 R, ui64 k) 
{
    // apply expansion permutation and returning 48bit data
    ui64 s_input = 0;
    for (ui8 i = 0; i < 48; i++)
    {
        s_input <<= 1;
        s_input |= (ui64)((R >> (32 - EXPANSION[i])) & LB32_MASK);
    }

    // XOR expand Ri with Ki, the round key
    s_input = s_input ^ k;

    //  apply S-Boxes function and return 32-bit data
    ui32 s_output = 0;
    for (ui8 i = 0; i < 8; i++)
    {
        // outer bits
        char row = (char)((s_input & (0x0000840000000000 >> 6 * i)) >> (42 - 6 * i));
        row = (row >> 4) | (row & 0x01);

        // middle 4 bits of input
        char column = (char)((s_input & (0x0000780000000000 >> 6 * i)) >> (43 - 6 * i));

        s_output <<= 4;
        s_output |= (ui32)(SBOX[i][16 * row + column] & 0x0f);
    }

    // apply round permutation
    ui32 f_result = 0;
    for (ui8 i = 0; i < 32; i++)
    {
        f_result <<= 1;
        f_result |= (s_output >> (32 - PBOX[i])) & LB32_MASK;
    }

    return f_result;
}

#include "HashFunction.h"
// #include <stdio.h>
// #include <stdint.h>
// #include <string.h>

uint32_t crc32_table[CALC_HASH_SIZE] = {};

void CRC32Init()
{
    uint32_t polynomial = HASH_CONST;
    for (uint32_t i = 0; i < CALC_HASH_SIZE; i++)
    {
        uint32_t crc = i;
        for (int j = 0; j < 8; j++)
        {
            crc = (crc >> 1) ^ ((crc & 1) ? polynomial : 0);
        }
        crc32_table[i] = crc;
    }
}

uint32_t CRC32(const uint8_t *data, size_t length)
{
    uint32_t crc = 0xFFFFFFFF;
    for (size_t i = 0; i < length; i++)
    {
        crc = (crc >> 8) ^ crc32_table[(crc ^ data[i]) & 0xFF];
    }
    return crc ^ 0xFFFFFFFF;
}
//
//  int main() {
//      CRC32Init();
//      const char *text = "Hello";
//      uint32_t hash = CRC32((const uint8_t *)text, strlen(text));
//     printf("CRC32: 0x%08X\n", hash);
//      return 0;
//  }

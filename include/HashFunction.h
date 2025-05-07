#ifndef HASH_FUNCTION_
#define HASH_FUNCTION_

#include "HashTable.h"

const int      CALC_HASH_SIZE  = 256;
const uint32_t HASH_CONST      =  0xEDB88320;

void     CRC32Init();
uint32_t CRC32    (const uint8_t *data, size_t length);

#endif

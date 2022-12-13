#include <iostream>
#include <cassert>

void* gamming(void* data, unsigned data_size, void* key, unsigned key_size)
{
    assert(data && data_size);
    if (!key || !key_size) return data;

    uint8_t* kptr = (uint8_t*)key;
    uint8_t* eptr = kptr + key_size;

    for (uint8_t* dptr = (uint8_t*)data; data_size--; dptr++)
    {
        *dptr ^= *kptr++;
        if (kptr == eptr) kptr = (uint8_t*)key;
    }
    return data;
}

void print_as_dump(void* data, unsigned data_size)
{
    for (uint8_t* dptr = (uint8_t*)data; data_size--; dptr++) printf("%.2X ", *dptr);
    printf("\n");
}

void print_as_text(void* data, unsigned data_size)
{
    for (uint8_t* dptr = (uint8_t*)data; data_size--; dptr++)
        if (isprint(*dptr)) printf("%c", *dptr);
        else printf("{\\x%.2X}", *dptr);
    printf("\n");
}

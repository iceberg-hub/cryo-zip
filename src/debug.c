#include <stdio.h>

#include "constants.h"

void print_frequencies(int frequencies[ASCII_SIZE])
{
    for (int i = 0; i < ASCII_SIZE; i++)
    {
        if (frequencies[i] > 0)
        {
            if (i >= 32 && i <= 126)
            {
                printf("'%c' -> %d\n", i, frequencies[i]);
            }
            else
            {
                printf("0x%02x -> %d\n", i, frequencies[i]);
            }
        }
    }
}
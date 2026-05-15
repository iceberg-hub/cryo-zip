#include <stdio.h>
#include "frequency.h"

void count_frequencies(FILE *file, int frequencies[256])
{
    rewind(file);

    int ch;

    while ((ch = fgetc(file)) != EOF)
    {
        frequencies[(unsigned char)ch]++;
    }

    rewind(file);
}
#include <stdio.h>
#include <string.h>

#include "constants.h"

void write_header(FILE *output, int frequencies[ASCII_SIZE])
{
    fwrite(MAGIC, sizeof(char),
           MAGIC_SIZE, output);

    fwrite(frequencies,
           sizeof(int), ASCII_SIZE, output);
}

int read_header(FILE *input, int frequencies[ASCII_SIZE])
{
    char magic[MAGIC_SIZE];

    fread(magic, sizeof(char), MAGIC_SIZE, input);

    if (memcmp(magic, MAGIC, MAGIC_SIZE) != 0)
    {
        return 0;
    }

    fread(frequencies, sizeof(int), ASCII_SIZE, input);

    return 1;
}
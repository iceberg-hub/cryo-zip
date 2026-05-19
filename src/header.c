#include <stdio.h>
#include <string.h>

#include "constants.h"
#include "header.h"

void write_header(FILE *output, Header *header)
{
    fwrite(MAGIC, sizeof(char), MAGIC_SIZE, output);

    fwrite(&header->original_size, sizeof(int), 1, output);

    fwrite(header->frequencies, sizeof(int), ASCII_SIZE, output);
}

int read_header(FILE *input, Header *header)
{
    char magic[MAGIC_SIZE];

    fread(magic, sizeof(char), MAGIC_SIZE, input);

    if (memcmp(magic, MAGIC, MAGIC_SIZE) != 0)
    {
        return 0;
    }

    fread(&header->original_size, sizeof(int), 1, input);

    fread(header->frequencies, sizeof(int), ASCII_SIZE, input);

    return 1;
}
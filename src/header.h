#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include "constants.h"

typedef struct
{
    int original_size;
    int frequencies[ASCII_SIZE];
} Header;

void write_header(
    FILE *output,
    Header *header);

int read_header(
    FILE *input,
    Header *header);

#endif
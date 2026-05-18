#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include "constants.h"

void write_header(FILE *output, int frequencies[ASCII_SIZE]);

int read_header(FILE *input, int frequencies[ASCII_SIZE]);

#endif
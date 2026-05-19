#ifndef DECODER_H
#define DECODER_H

#include <stdio.h>

#include "huffman.h"

void decode_file(FILE *input, FILE *output, HuffmanNode *root, int original_size);

#endif
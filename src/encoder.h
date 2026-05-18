#ifndef ENCODER_H
#define ENCODER_H

#include <stdio.h>

#include "huffman.h"
#include "constants.h"

typedef struct
{
    char codes[ASCII_SIZE][ASCII_SIZE];
} CodeTable;

void build_code_table(
    HuffmanNode *root,
    CodeTable *table);

void encode_file(
    FILE *input,
    FILE *output,
    CodeTable *table);

void build_codes_recursive(HuffmanNode *node, CodeTable *table, char *buffer, int depth);

#endif
#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "constants.h"

typedef struct HuffmanNode {
    unsigned char character;
    int frequency;
    struct HuffmanNode *left;
    struct HuffmanNode *right;
} HuffmanNode;

int is_leaf(HuffmanNode *node);

HuffmanNode *create_node(
    unsigned char character,
    int frequency,
    HuffmanNode *left,
    HuffmanNode *right
);

HuffmanNode *build_huffman_tree(int frequencies[ASCII_SIZE]);

void free_huffman_tree(HuffmanNode *node);

void print_tree(HuffmanNode *node, int depth);

#endif
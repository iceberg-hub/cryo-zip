#ifndef HEAP_H
#define HEAP_H

#include "huffman.h"

typedef struct {
    HuffmanNode **data;
    int size;
    int capacity;
} MinHeap;

MinHeap *create_heap(int capacity);

void insert_heap(MinHeap *heap, HuffmanNode *node);

HuffmanNode *extract_min(MinHeap *heap);

void free_heap(MinHeap *heap);

#endif
#include <stdlib.h>
#include <stdio.h>

#include "huffman.h"
#include "heap.h"
#include "constants.h"

HuffmanNode *create_node(unsigned char character,
                         int frequency,
                         HuffmanNode *left,
                         HuffmanNode *right)
{
    HuffmanNode *node = malloc(sizeof(HuffmanNode));

    node->character = character;
    node->frequency = frequency;
    node->left = left;
    node->right = right;

    return node;
}

int is_leaf(HuffmanNode *node)
{
    return node->left == NULL && node->right == NULL;
}

HuffmanNode *build_huffman_tree(int frequencies[ASCII_SIZE])
{
    MinHeap *heap = create_heap(ASCII_SIZE);

    for (int i = 0; i < ASCII_SIZE; i++)
    {
        if (frequencies[i] > 0)
        {
            insert_heap(
                heap,
                create_node(i, frequencies[i], NULL, NULL));
        }
    }

    while (heap->size > 1)
    {
        HuffmanNode *left = extract_min(heap);
        HuffmanNode *right = extract_min(heap);

        HuffmanNode *merged = create_node(
            0,
            left->frequency + right->frequency,
            left,
            right);

        insert_heap(heap, merged);
    }

    return extract_min(heap);
}

void free_huffman_tree(HuffmanNode *node)
{
    if (node == NULL)
    {
        return;
    }

    free_huffman_tree(node->left);
    free_huffman_tree(node->right);

    free(node);
}

void print_tree(HuffmanNode *node, int depth)
{
    if (node == NULL)
    {
        return;
    }

    for (int i = 0; i < depth; i++)
    {
        printf("  ");
    }

    if (node->left == NULL && node->right == NULL)
    {
        printf("'%c' (%d)\n",
               node->character,
               node->frequency);
    }
    else
    {
        printf("* (%d)\n", node->frequency);
    }

    print_tree(node->left, depth + 1);
    print_tree(node->right, depth + 1);
}
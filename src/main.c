#include <stdio.h>
#include <stdlib.h>

#include "constants.h"
#include "frequency.h"
#include "huffman.h"

void print_frequencies(int frequencies[ASCII_SIZE])
{
    for (int i = 0; i < ASCII_SIZE; i++)
    {
        if (frequencies[i] > 0)
        {
            if (i >= 32 && i <= 126)
            {
                printf("'%c' -> %d\n", i, frequencies[i]);
            }
            else
            {
                printf("0x%02x -> %d\n", i, frequencies[i]);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");

    if (!file)
    {
        perror("Failed to open file");
        return 1;
    }

    int frequencies[ASCII_SIZE] = {0};

    count_frequencies(file, frequencies);

    fclose(file);

    print_frequencies(frequencies);

    HuffmanNode *root = build_huffman_tree(frequencies);

    if (root == NULL)
    {
        fprintf(stderr, "Failed to build Huffman tree\n");
        return 1;
    }

    printf("Root frequency: %d\n", root->frequency);

    print_tree(root, 0);

    free_huffman_tree(root);

    return 0;
}
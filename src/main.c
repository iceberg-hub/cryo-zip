#include <stdio.h>
#include <stdlib.h>

#include "constants.h"
#include "frequency.h"
#include "header.h"
#include "huffman.h"
#include "debug.h"

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

    write_header(file, frequencies);

    printf("HEADER %d", read_header(file, frequencies));

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
#include <stdio.h>

#include "huffman.h"
#include "encoder.h"
#include "constants.h"
#include "frequency.h"
#include "header.h"
#include "debug.h"

int encode_command(const char *input_path, const char *output_path)
{

    FILE *input = fopen(input_path, "rb");

    if (!input)
    {
        perror("Failed to open input file");
        return 1;
    }

    FILE *output = fopen(output_path, "wb");

    if (!output)
    {
        perror("Failed to open output file");
        fclose(input);
        return 1;
    }

    int frequencies[ASCII_SIZE] = {0};

    count_frequencies(input, frequencies);

    print_frequencies(frequencies);

    HuffmanNode *root = build_huffman_tree(frequencies);

    if (root == NULL)
    {
        fprintf(stderr, "Failed to build Huffman tree\n");
        fclose(input);
        fclose(output);
        return 1;
    }

    print_tree(root, 0);

    CodeTable table = {0, 0};

    build_code_table(root, &table);

    write_header(output, frequencies);

    encode_file(input, output, &table);

    fclose(input);
    fclose(output);

    free_huffman_tree(root);
    return 0;
}

void read_command(const char *input_path)
{
    printf("Read not implemented yet.\n");
}

void decode_command(const char *input_path, const char *output_path)
{
    printf("Decode not implemented yet.\n");
}
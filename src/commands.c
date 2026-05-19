#include <stdio.h>

#include "huffman.h"
#include "encoder.h"
#include "constants.h"
#include "frequency.h"
#include "header.h"
#include "debug.h"
#include "decoder.h"

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

    CodeTable table = {0};

    build_code_table(root, &table);

    Header header = {0};

    for (int i = 0; i < ASCII_SIZE; i++)
    {
        header.frequencies[i] =
            frequencies[i];

        header.original_size +=
            frequencies[i];
    }

    write_header(output, &header);

    encode_file(input, output, &table);

    fclose(input);
    fclose(output);

    free_huffman_tree(root);
    return 0;
}

int read_command(const char *input_path)
{
    FILE *input = fopen(input_path, "rb");

    if (!input)
    {
        perror("Failed to open input file");
        return 1;
    }

    printf("Reading header...");

    int frequencies[ASCII_SIZE] = {0};

    Header header = {0};

    for (int i = 0; i < ASCII_SIZE; i++)
    {
        header.frequencies[i] =
            frequencies[i];

        header.original_size +=
            frequencies[i];
    }

    int valid = read_header(input, &header);

    if (!valid)
    {
        fprintf(stderr, "Invalid compressed file\n");
        fclose(input);
        return 1;
    }

    printf("Building tree for decoding...");

    HuffmanNode *root = build_huffman_tree(frequencies);

    if (root == NULL)
    {
        fprintf(stderr, "Failed to rebuild Huffman tree\n");
        fclose(input);
        return 1;
    }

    free_huffman_tree(root);

    fclose(input);
    return 0;
}

int decode_command(const char *input_path, const char *output_path)
{
    FILE *input = fopen(input_path, "rb");

    if (!input)
    {
        perror("Failed to open input");
        return 1;
    }

    FILE *output = fopen(output_path, "wb");

    if (!output)
    {
        perror("Failed to open output");
        fclose(input);
        return 1;
    }

    Header header = {0};

    if (!read_header(input, &header))
    {
        fprintf(stderr, "Invalid compressed file\n");
        fclose(input);
        fclose(output);
        return 1;
    }

    HuffmanNode *root = build_huffman_tree(header.frequencies);

    if (!root)
    {
        fprintf(stderr, "Failed to rebuild tree\n");
        fclose(input);
        fclose(output);
        return 1;
    }

    decode_file(input, output, root, header.original_size);

    free_huffman_tree(root);

    fclose(input);
    fclose(output);

    printf("File decoded successfully.\n");
    return 0;
}
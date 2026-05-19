#include <stdio.h>

#include "decoder.h"

void decode_file(FILE *input, FILE *output, HuffmanNode *root, int original_size)
{
    HuffmanNode *current = root;

    int decoded = 0;

    int byte;

    while (decoded < original_size && (byte = fgetc(input)) != EOF)
    {
        for (int i = 7; i >= 0; i--)
        {
            int bit = (byte >> i) & 1;

            if (bit == 0)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }

            if (is_leaf(current))
            {
                fputc(current->character, output);

                decoded++;

                current = root;

                if (decoded >= original_size)
                {
                    break;
                }
            }
        }
    }
}
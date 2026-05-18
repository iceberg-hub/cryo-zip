#include <string.h>

#include "encoder.h"

void encode_file(FILE *input, FILE *output, CodeTable *table)
{
    rewind(input);

    unsigned char current_byte = 0;

    int bit_count = 0;

    int ch;

    while ((ch = fgetc(input)) != EOF)
    {
        char *code = table->codes[(unsigned char)ch];

        for (int i = 0; code[i] != '\0'; i++)
        {
            current_byte <<= 1;

            if (code[i] == '1')
            {
                current_byte |= 1;
            }

            bit_count++;

            if (bit_count == 8)
            {
                fputc(current_byte, output);

                current_byte = 0;
                bit_count = 0;
            }
        }
    }

    if (bit_count > 0)
    {
        current_byte <<= (8 - bit_count);

        fputc(current_byte, output);
    }
}

void build_code_table(HuffmanNode *root, CodeTable *table)
{
    char buffer[ASCII_SIZE];

    build_codes_recursive(root, table, buffer, 0);
}

void build_codes_recursive(HuffmanNode *node, CodeTable *table, char *buffer, int depth)
{
    if (node == NULL)
    {
        return;
    }

    if (is_leaf(node))
    {
        buffer[depth] = '\0';

        strcpy(
            table->codes[node->character],
            buffer);

        return;
    }

    buffer[depth] = '0';

    build_codes_recursive(
        node->left,
        table,
        buffer,
        depth + 1);

    buffer[depth] = '1';

    build_codes_recursive(
        node->right,
        table,
        buffer,
        depth + 1);
}
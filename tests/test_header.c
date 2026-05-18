#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "../src/constants.h"
#include "../src/header.h"

void test_write_and_read_header()
{
    int frequencies[ASCII_SIZE] = {0};

    frequencies['a'] = 3;
    frequencies['b'] = 2;
    frequencies['c'] = 1;

    FILE *file = tmpfile();

    assert(file != NULL);

    write_header(file, frequencies);

    rewind(file);

    int loaded[ASCII_SIZE] = {0};

    int result = read_header(file, loaded);

    assert(result == 1);

    for (int i = 0; i < ASCII_SIZE; i++)
    {
        assert(frequencies[i] == loaded[i]);
    }

    fclose(file);
}

void test_invalid_magic_bytes()
{
    FILE *file = tmpfile();

    assert(file != NULL);

    const char invalid_magic[] = "BAD!";

    fwrite(invalid_magic, sizeof(char), 4, file);

    rewind(file);

    int frequencies[ASCII_SIZE] = {0};

    int result = read_header(file, frequencies);

    assert(result == 0);

    fclose(file);
}

void test_header_preserves_zero_frequencies()
{
    int frequencies[ASCII_SIZE] = {0};

    frequencies['x'] = 10;

    FILE *file = tmpfile();

    assert(file != NULL);

    write_header(file, frequencies);

    rewind(file);

    int loaded[ASCII_SIZE] = {0};

    int result = read_header(file, loaded);

    assert(result == 1);

    assert(loaded['x'] == 10);

    for (int i = 0; i < ASCII_SIZE; i++)
    {
        if (i != 'x')
        {
            assert(loaded[i] == 0);
        }
    }

    fclose(file);
}

void test_multiple_headers()
{
    int frequencies1[ASCII_SIZE] = {0};
    int frequencies2[ASCII_SIZE] = {0};

    frequencies1['a'] = 1;
    frequencies2['z'] = 99;

    FILE *file = tmpfile();

    assert(file != NULL);

    write_header(file, frequencies1);
    write_header(file, frequencies2);

    rewind(file);

    int loaded1[ASCII_SIZE] = {0};
    int loaded2[ASCII_SIZE] = {0};

    assert(read_header(file, loaded1) == 1);
    assert(read_header(file, loaded2) == 1);

    assert(loaded1['a'] == 1);
    assert(loaded2['z'] == 99);

    fclose(file);
}
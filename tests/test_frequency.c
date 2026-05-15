#include <assert.h>
#include <stdio.h>

#include "../src/frequency.h"

FILE *create_temp_file(const char *content)
{
    FILE *file = tmpfile();

    fputs(content, file);

    rewind(file);

    return file;
}

void test_count_frequencies_basic()
{
    int frequencies[256] = {0};

    FILE *file = create_temp_file("aaabbc");

    count_frequencies(file, frequencies);

    fclose(file);

    assert(frequencies['a'] == 3);
    assert(frequencies['b'] == 2);
    assert(frequencies['c'] == 1);
}

void test_count_frequencies_empty()
{
    int frequencies[256] = {0};

    FILE *file = create_temp_file("");

    count_frequencies(file, frequencies);

    fclose(file);

    for (int i = 0; i < 256; i++)
    {
        assert(frequencies[i] == 0);
    }
}
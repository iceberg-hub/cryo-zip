#include <stdio.h>

void test_count_frequencies_basic();
void test_count_frequencies_empty();

int main()
{
    printf("Running tests...\n");

    test_count_frequencies_basic();
    printf("test_count_frequencies_basic passed\n");

    test_count_frequencies_empty();
    printf("test_count_frequencies_empty passed\n");

    printf("All tests passed.\n");

    return 0;
}
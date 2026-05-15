#include <stdio.h>

// Frequencies
void test_count_frequencies_basic();
void test_count_frequencies_empty();

// Heap
void test_create_heap();
void test_insert_heap_single();
void test_extract_min();
void test_heap_ordering();

// Huffman
void test_create_node();
void test_is_leaf();
void test_build_huffman_tree();
void test_build_huffman_tree_single_character();

int main()
{
    printf("Running tests...\n");

    test_count_frequencies_basic();
    printf("test_count_frequencies_basic passed\n");

    test_count_frequencies_empty();
    printf("test_count_frequencies_empty passed\n");

    test_create_heap();
    printf("test_create_heap passed\n");

    test_insert_heap_single();
    printf("test_insert_heap_single passed\n");

    test_extract_min();
    printf("test_extract_min passed\n");

    test_heap_ordering();
    printf("test_heap_ordering passed\n");

    test_create_node();
    printf("test_create_node passed\n");

    test_is_leaf();
    printf("test_is_leaf passed\n");

    test_build_huffman_tree();
    printf("test_build_huffman_tree passed\n");

    test_build_huffman_tree_single_character();
    printf("test_build_huffman_tree_single_character passed\n");

    printf("All tests passed.\n");

    return 0;
}
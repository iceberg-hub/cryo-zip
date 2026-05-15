#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "../src/heap.h"
#include "../src/huffman.h"

void test_create_heap()
{
    MinHeap *heap = create_heap(10);

    assert(heap != NULL);
    assert(heap->size == 0);
    assert(heap->capacity == 10);

    free_heap(heap);
}

void test_insert_heap_single()
{
    MinHeap *heap = create_heap(10);

    HuffmanNode *node = create_node('a', 5, NULL, NULL);

    insert_heap(heap, node);

    assert(heap->size == 1);
    assert(heap->data[0]->frequency == 5);

    free(node);
    free_heap(heap);
}

void test_extract_min()
{
    MinHeap *heap = create_heap(10);

    insert_heap(heap, create_node('a', 5, NULL, NULL));
    insert_heap(heap, create_node('b', 2, NULL, NULL));
    insert_heap(heap, create_node('c', 1, NULL, NULL));

    HuffmanNode *min = extract_min(heap);

    assert(min != NULL);
    assert(min->character == 'c');
    assert(min->frequency == 1);

    free(min);

    min = extract_min(heap);

    assert(min->character == 'b');
    assert(min->frequency == 2);

    free(min);

    min = extract_min(heap);

    assert(min->character == 'a');
    assert(min->frequency == 5);

    free(min);

    free_heap(heap);
}

void test_heap_ordering()
{
    MinHeap *heap = create_heap(10);

    insert_heap(heap, create_node('a', 10, NULL, NULL));
    insert_heap(heap, create_node('b', 3, NULL, NULL));
    insert_heap(heap, create_node('c', 7, NULL, NULL));
    insert_heap(heap, create_node('d', 1, NULL, NULL));

    int previous = -1;

    while (heap->size > 0)
    {
        HuffmanNode *node = extract_min(heap);

        assert(node->frequency >= previous);

        previous = node->frequency;

        free(node);
    }

    free_heap(heap);
}
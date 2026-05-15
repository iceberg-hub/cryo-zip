#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "heap.h"

static void swap_nodes(HuffmanNode **a, HuffmanNode **b)
{
    HuffmanNode *temp = *a;
    *a = *b;
    *b = temp;
}

static void heapify_up(MinHeap *heap, int index)
{
    while (index > 0)
    {
        int parent = (index - 1) / 2;

        if (heap->data[parent]->frequency <= heap->data[index]->frequency)
        {
            break;
        }

        swap_nodes(&heap->data[parent], &heap->data[index]);

        index = parent;
    }
}

static void heapify_down(MinHeap *heap, int index)
{
    while (1)
    {
        int left = (2 * index) + 1;
        int right = (2 * index) + 2;
        int smallest = index;

        bool is_left_lower_than_smallest = left < heap->size &&
                                           heap->data[left]->frequency <
                                               heap->data[smallest]->frequency;

        if (is_left_lower_than_smallest)
        {
            smallest = left;
        }

        bool is_right_lower_than_smallest = right < heap->size &&
                                            heap->data[right]->frequency <
                                                heap->data[smallest]->frequency;

        if (is_right_lower_than_smallest)
        {
            smallest = right;
        }

        if (smallest == index)
        {
            break;
        }

        swap_nodes(
            &heap->data[index],
            &heap->data[smallest]);

        index = smallest;
    }
}

MinHeap *create_heap(int capacity)
{
    MinHeap *heap = malloc(sizeof(MinHeap));

    if (heap == NULL)
    {
        return NULL;
    }

    heap->data = malloc(sizeof(HuffmanNode *) * capacity);

    if (heap->data == NULL)
    {
        free(heap);
        return NULL;
    }

    heap->size = 0;
    heap->capacity = capacity;

    return heap;
}

void insert_heap(MinHeap *heap, HuffmanNode *node)
{
    if (heap->size >= heap->capacity)
    {
        fprintf(stderr, "Heap overflow\n");
        exit(EXIT_FAILURE);
    }

    heap->data[heap->size] = node;
    heap->size++;

    heapify_up(heap, heap->size - 1);
}

HuffmanNode *extract_min(MinHeap *heap)
{
    if (heap->size == 0)
    {
        return NULL;
    }

    HuffmanNode *min = heap->data[0];

    heap->size--;

    heap->data[0] = heap->data[heap->size];

    heapify_down(heap, 0);

    return min;
}

void free_heap(MinHeap *heap)
{
    free(heap->data);
    free(heap);
}

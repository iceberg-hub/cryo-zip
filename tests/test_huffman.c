#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "../src/constants.h"
#include "../src/huffman.h"

static int count_leaves(HuffmanNode *node)
{
    if (node == NULL)
    {
        return 0;
    }

    if (is_leaf(node))
    {
        return 1;
    }

    return count_leaves(node->left) + count_leaves(node->right);
}

void test_create_node()
{
    HuffmanNode *node = create_node(
        'a',
        5,
        NULL,
        NULL);

    assert(node != NULL);

    assert(node->character == 'a');
    assert(node->frequency == 5);

    assert(node->left == NULL);
    assert(node->right == NULL);

    free(node);
}

void test_is_leaf()
{
    HuffmanNode *leaf = create_node(
        'a',
        1,
        NULL,
        NULL);

    assert(is_leaf(leaf) == 1);

    HuffmanNode *parent = create_node(
        0,
        2,
        leaf,
        NULL);

    assert(is_leaf(parent) == 0);

    free(parent);
    free(leaf);
}

void test_build_huffman_tree()
{
    int frequencies[ASCII_SIZE] = {0};

    frequencies['a'] = 3;
    frequencies['b'] = 2;
    frequencies['c'] = 1;

    HuffmanNode *root =
        build_huffman_tree(frequencies);

    assert(root != NULL);

    assert(root->frequency == 6);

    assert(count_leaves(root) == 3);

    free_huffman_tree(root);
}

void test_build_huffman_tree_single_character()
{
    int frequencies[ASCII_SIZE] = {0};

    frequencies['a'] = 6;

    HuffmanNode *root =
        build_huffman_tree(frequencies);

    assert(root != NULL);

    assert(root->frequency == 6);

    assert(is_leaf(root));

    assert(root->character == 'a');

    free_huffman_tree(root);
}
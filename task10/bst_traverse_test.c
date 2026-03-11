#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

#define SUCCESS 0
#define FAIL 1

int compare_int(int a, int b)
{
    return a - b;
}

void print_int(int value)
{
    printf("%d ", value);
}

t_btree* create_tree_from_array(int* values, int count)
{
    if (count == 0) return NULL;
    
    t_btree* root = bstree_create_node(values[0]);
    if (!root) return NULL;
    
    for (int i = 1; i < count; i++) {
        bstree_insert(root, values[i], compare_int);
    }
    
    return root;
}

void print_tree_visual(t_btree *root, int space, int level)
{
    if (!root) return;
    
    space += level;
    
    print_tree_visual(root->right, space, level);
    
    printf("\n");
    for (int i = level; i < space; i++) {
        printf("  ");
    }
    printf("%d\n", root->item);
    
    print_tree_visual(root->left, space, level);
}

void test_simple_tree()
{
    printf("\n========================================\n");
    printf("Test 1: Simple Tree\n");
    printf("========================================\n");
    
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int count = sizeof(values) / sizeof(values[0]);
    
    t_btree* root = create_tree_from_array(values, count);
    
    printf("Tree structure:\n");
    print_tree_visual(root, 0, 5);
    
    printf("\nInfix traversal (sorted order - ascending):\n");
    bstree_apply_infix(root, print_int);
    printf("\n");
    
    printf("\nPrefix traversal (root -> left -> right):\n");
    bstree_apply_prefix(root, print_int);
    printf("\n");
    
    printf("\nPostfix traversal (left -> right -> root):\n");
    bstree_apply_postfix(root, print_int);
    printf("\n");
    
}

void test_duplicate_tree()
{
    printf("\n========================================\n");
    printf("Test 2: Tree with Duplicates\n");
    printf("========================================\n");
    
    int values[] = {50, 30, 70, 30, 50, 80, 40, 60, 40};
    int count = sizeof(values) / sizeof(values[0]);
    
    t_btree* root = create_tree_from_array(values, count);
    
    printf("Tree structure (duplicates should be ignored):\n");
    print_tree_visual(root, 0, 5);
    
    printf("\nInfix traversal (sorted order - ascending):\n");
    bstree_apply_infix(root, print_int);
    printf("\n");
    
    printf("\nPrefix traversal (root -> left -> right):\n");
    bstree_apply_prefix(root, print_int);
    printf("\n");
    
    printf("\nPostfix traversal (left -> right -> root):\n");
    bstree_apply_postfix(root, print_int);
    printf("\n");
}

void test_complex_tree()
{
    printf("\n========================================\n");
    printf("Test 3: Complex Tree\n");
    printf("========================================\n");
    
    int values[] = {100, 50, 150, 25, 75, 125, 175, 110, 130, 10, 200, 5, 15, 90};
    int count = sizeof(values) / sizeof(values[0]);
    
    t_btree* root = create_tree_from_array(values, count);
    
    printf("Tree structure:\n");
    print_tree_visual(root, 0, 5);
    
    printf("\nInfix traversal (sorted order - ascending):\n");
    bstree_apply_infix(root, print_int);
    printf("\n");
    
    printf("\nPrefix traversal (root -> left -> right):\n");
    bstree_apply_prefix(root, print_int);
    printf("\n");
    
    printf("\nPostfix traversal (left -> right -> root):\n");
    bstree_apply_postfix(root, print_int);
    printf("\n");
}

void test_left_skewed_tree()
{
    printf("\n========================================\n");
    printf("Test 4: Left-Skewed Tree\n");
    printf("========================================\n");
    
    int values[] = {50, 40, 30, 20, 10, 5};
    int count = sizeof(values) / sizeof(values[0]);
    
    t_btree* root = create_tree_from_array(values, count);
    
    printf("Tree structure (left-skewed):\n");
    print_tree_visual(root, 0, 5);
    
    printf("\nInfix traversal (sorted order - ascending):\n");
    bstree_apply_infix(root, print_int);
    printf("\n");
    
    printf("\nPrefix traversal (root -> left -> right):\n");
    bstree_apply_prefix(root, print_int);
    printf("\n");
    
    printf("\nPostfix traversal (left -> right -> root):\n");
    bstree_apply_postfix(root, print_int);
    printf("\n");
}

void test_right_skewed_tree()
{
    printf("\n========================================\n");
    printf("Test 5: Right-Skewed Tree\n");
    printf("========================================\n");
    
    int values[] = {5, 10, 20, 30, 40, 50};
    int count = sizeof(values) / sizeof(values[0]);
    
    t_btree* root = create_tree_from_array(values, count);
    
    printf("Tree structure (right-skewed):\n");
    print_tree_visual(root, 0, 5);
    
    printf("\nInfix traversal (sorted order - ascending):\n");
    bstree_apply_infix(root, print_int);
    printf("\n");
    
    printf("\nPrefix traversal (root -> left -> right):\n");
    bstree_apply_prefix(root, print_int);
    printf("\n");
    
    printf("\nPostfix traversal (left -> right -> root):\n");
    bstree_apply_postfix(root, print_int);
    printf("\n");
}

// Тест 6: Пустое дерево
void test_empty_tree()
{
    printf("\n========================================\n");
    printf("Test 6: Empty Tree\n");
    printf("========================================\n");
    
    t_btree* root = NULL;
    
    printf("Empty tree traversals (should print nothing):\n");
    
    printf("Infix: ");
    bstree_apply_infix(root, print_int);
    printf("\n");
    
    printf("Prefix: ");
    bstree_apply_prefix(root, print_int);
    printf("\n");
    
    printf("Postfix: ");
    bstree_apply_postfix(root, print_int);
    printf("\n");
}

int main()
{
    printf("========================================\n");
    printf("BST Traversal Tests\n");
    printf("Three styles: Infix, Prefix, Postfix\n");
    printf("========================================\n");
    
    test_simple_tree();
    test_duplicate_tree();
    test_complex_tree();
    test_left_skewed_tree();
    test_right_skewed_tree();
    test_empty_tree();
    
    printf("\n========================================\n");
    printf("All tests completed\n");
    printf("========================================\n");
    
    return SUCCESS;
}
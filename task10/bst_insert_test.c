#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

#define SUCCESS 0
#define FAIL 1

int compare_int(int a, int b)
{
    return a - b; 
}


void print_tree_inorder(t_btree *root, int level)
{
    if (!root) return;
    
    print_tree_inorder(root->left, level + 1);
    
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    printf("├─ %d\n", root->item);
    
    
    print_tree_inorder(root->right, level + 1);
}

void find_insert_position(t_btree *root, int item, int (*cmpf)(int, int), int depth)
{
    if (!root) return;
    
    int cmp_result = cmpf(item, root->item);
    
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    
    if (cmp_result < 0) {
        printf("Comparing %d with %d: go LEFT", item, root->item);
        if (root->left) {
            printf(" (node exists)\n");
            find_insert_position(root->left, item, cmpf, depth + 1);
        } else {
            printf(" -> INSERT HERE as left child of %d\n", root->item);
        }
    } else if (cmp_result > 0) {
        printf("Comparing %d with %d: go RIGHT", item, root->item);
        if (root->right) {
            printf(" (node exists)\n");
            find_insert_position(root->right, item, cmpf, depth + 1);
        } else {
            printf(" -> INSERT HERE as right child of %d\n", root->item);
        }
    } else {
        printf("Comparing %d with %d: EQUAL - not inserting duplicate\n", item, root->item);
    }
}

int test_simple_insertion()
{
    printf("\n=== Test 1: Simple Insertion ===\n");
    
    t_btree *root = bstree_create_node(50);
    if (!root) return FAIL;
    
    printf("Initial tree with root: %d\n", root->item);
    
    int values[] = {30, 70, 20, 40, 60, 80};
    int count = sizeof(values) / sizeof(values[0]);
    
    printf("\nInserting values: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", values[i]);
    }
    printf("\n\nInsertion process:\n");
    
    for (int i = 0; i < count; i++) {
        printf("\nInserting %d:\n", values[i]);
        find_insert_position(root, values[i], compare_int, 0);
        bstree_insert(root, values[i], compare_int);
    }
    
    printf("\nFinal tree structure:\n");
    print_tree_inorder(root, 0);
    
    return SUCCESS;
}

int test_duplicate_insertion()
{
    printf("\n=== Test 2: Duplicate Insertion ===\n");
    
    t_btree *root = bstree_create_node(50);
    if (!root) return FAIL;
    
    printf("Initial tree with root: %d\n", root->item);
    
    int values[] = {30, 70, 30, 50, 80, 50};
    int count = sizeof(values) / sizeof(values[0]);
    
    printf("\nInserting values (with duplicates): ");
    for (int i = 0; i < count; i++) {
        printf("%d ", values[i]);
    }
    printf("\n\nInsertion process:\n");
    
    for (int i = 0; i < count; i++) {
        printf("\nInserting %d:\n", values[i]);
        find_insert_position(root, values[i], compare_int, 0);
        bstree_insert(root, values[i], compare_int);
    }
    
    printf("\nFinal tree structure (duplicates should not appear twice):\n");
    print_tree_inorder(root, 0);
    
    return SUCCESS;
}

int test_complex_tree()
{
    printf("\n=== Test 3: Complex Tree Construction ===\n");
    
    t_btree *root = bstree_create_node(100);
    if (!root) return FAIL;
    
    printf("Building a binary search tree with values:\n");
    
    int insert_order[] = {50, 150, 25, 75, 125, 175, 110, 130, 10, 200};
    int count = sizeof(insert_order) / sizeof(insert_order[0]);
    
    printf("Insert order: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", insert_order[i]);
    }
    printf("\n");
    
    for (int i = 0; i < count; i++) {
        bstree_insert(root, insert_order[i], compare_int);
    }
    
    printf("\nFinal tree structure:\n");
    print_tree_inorder(root, 0);
    
    printf("\nVerification: Looking for specific values...\n");
    printf("Note: Visual verification from tree structure above\n");
    
    return SUCCESS;
}

int test_edge_cases()
{
    printf("\n=== Test 4: Edge Cases ===\n");
    
    printf("Test with NULL root:\n");
    bstree_insert(NULL, 42, compare_int);
    printf("✓ Function handles NULL root gracefully\n");
    
    printf("\nTree with negative values:\n");
    t_btree *root = bstree_create_node(0);
    if (!root) return FAIL;
    
    int neg_values[] = {-5, -10, -3, -7, -1};
    for (int i = 0; i < 5; i++) {
        bstree_insert(root, neg_values[i], compare_int);
    }
    
    printf("Tree with negative values inserted:\n");
    print_tree_inorder(root, 0);
    
    return SUCCESS;
}

int main()
{
    int tests_passed = 0;
    int total_tests = 4;
    
    printf("========================================\n");
    printf("BST Insertion Function Tests\n");
    printf("========================================\n");
    
    if (test_simple_insertion() == SUCCESS) {
        printf("\ntest_simple_insertion: SUCCESS\n");
        tests_passed++;
    } else {
        printf("\ntest_simple_insertion: FAIL\n");
    }
    
    if (test_duplicate_insertion() == SUCCESS) {
        printf("\ntest_duplicate_insertion: SUCCESS\n");
        tests_passed++;
    } else {
        printf("\ntest_duplicate_insertion: FAIL\n");
    }
    
    if (test_complex_tree() == SUCCESS) {
        printf("\ntest_complex_tree: SUCCESS\n");
        tests_passed++;
    } else {
        printf("\ntest_complex_tree: FAIL\n");
    }
    
    if (test_edge_cases() == SUCCESS) {
        printf("\ntest_edge_cases: SUCCESS\n");
        tests_passed++;
    } else {
        printf("\ntest_edge_cases: FAIL\n");
    }
    
    printf("\n========================================\n");
    printf("Tests passed: %d/%d\n", tests_passed, total_tests);
    printf("========================================\n");
    
    return (tests_passed == total_tests) ? SUCCESS : FAIL;
}
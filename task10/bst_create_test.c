#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

#define SUCCESS 0
#define FAIL 1

void print_node_info(t_btree *node, const char* node_name)
{
    if (node) {
        printf("Node '%s': item = %d, left = %p, right = %p\n", 
               node_name, node->item, (void*)node->left, (void*)node->right);
    } else {
        printf("Node '%s': NULL\n", node_name);
    }
}

int test_create_positive()
{
    int test_value = 42;
    t_btree *node = bstree_create_node(test_value);
    
    if (!node) {
        printf("Failed to create node with positive value %d\n", test_value);
        return FAIL;
    }
    
    int result = SUCCESS;
    
    if (node->item != test_value) {
        printf("Error: node->item = %d, expected %d\n", node->item, test_value);
        result = FAIL;
    }
    
    if (node->left != NULL) {
        printf("Error: node->left should be NULL\n");
        result = FAIL;
    }
    
    if (node->right != NULL) {
        printf("Error: node->right should be NULL\n");
        result = FAIL;
    }
    
    print_node_info(node, "positive_test");
    free(node);
    
    return result;
}

int test_create_negative()
{
    int test_value = -17;
    t_btree *node = bstree_create_node(test_value);
    
    if (!node) {
        printf("Failed to create node with negative value %d\n", test_value);
        return FAIL;
    }

    int result = SUCCESS;
    
    if (node->item != test_value) {
        printf("Error: node->item = %d, expected %d\n", node->item, test_value);
        result = FAIL;
    }
    
    if (node->left != NULL) {
        printf("Error: node->left should be NULL\n");
        result = FAIL;
    }
    
    if (node->right != NULL) {
        printf("Error: node->right should be NULL\n");
        result = FAIL;
    }
    
    print_node_info(node, "negative_test");
    free(node);
    
    return result;
}

int test_create_zero()
{
    int test_value = 0;
    t_btree *node = bstree_create_node(test_value);
    
    if (!node) {
        printf("Failed to create node with zero value %d\n", test_value);
        return FAIL;
    }
    
    int result = SUCCESS;
    
    if (node->item != test_value) {
        printf("Error: node->item = %d, expected %d\n", node->item, test_value);
        result = FAIL;
    }
    
    if (node->left != NULL) {
        printf("Error: node->left should be NULL\n");
        result = FAIL;
    }
    
    if (node->right != NULL) {
        printf("Error: node->right should be NULL\n");
        result = FAIL;
    }
    
    print_node_info(node, "zero_test");
    free(node);
    
    return result;
}

int test_multiple_nodes()
{
    t_btree *node1 = bstree_create_node(10);
    t_btree *node2 = bstree_create_node(20);
    t_btree *node3 = bstree_create_node(30);
    
    if (!node1 || !node2 || !node3) {
        printf("Failed to create multiple nodes\n");
        free(node1);
        free(node2);
        free(node3);
        return FAIL;
    }
    
    int result = SUCCESS;
    
    if (node1->item != 10 || node2->item != 20 || node3->item != 30) {
        printf("Error: incorrect values in multiple nodes\n");
        result = FAIL;
    }
    
    printf("\nMultiple nodes test:\n");
    print_node_info(node1, "node1");
    print_node_info(node2, "node2");
    print_node_info(node3, "node3");
    
    free(node1);
    free(node2);
    free(node3);
    
    return result;
}

int main()
{
    int tests_passed = 0;
    int total_tests = 4;
    
    printf("Running BST node creation tests...\n");
    printf("====================================\n");
    
    if (test_create_positive() == SUCCESS) {
        printf("test_create_positive: SUCCESS\n");
        tests_passed++;
    } else {
        printf("test_create_positive: FAIL\n");
    }
    
    if (test_create_negative() == SUCCESS) {
        printf("test_create_negative: SUCCESS\n");
        tests_passed++;
    } else {
        printf("test_create_negative: FAIL\n");
    }
    
    if (test_create_zero() == SUCCESS) {
        printf("test_create_zero: SUCCESS\n");
        tests_passed++;
    } else {
        printf("test_create_zero: FAIL\n");
    }
    
    if (test_multiple_nodes() == SUCCESS) {
        printf("test_multiple_nodes: SUCCESS\n");
        tests_passed++;
    } else {
        printf("test_multiple_nodes: FAIL\n");
    }
    
    printf("====================================\n");
    printf("Tests passed: %d/%d\n", tests_passed, total_tests);
    
    return (tests_passed == total_tests) ? SUCCESS : FAIL;
}
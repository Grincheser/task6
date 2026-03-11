#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#define SUCCESS 0
#define FAIL 1

int test_add_door() {
    struct door door1 = {1, 0};
    struct door door2 = {2, 0};
    struct door door3 = {3, 0};
    
    node* root = init(door1);
    if (!root) return FAIL;
    
    node* second = add_door(root, door2);
    if (!second || root->next != second) return FAIL;
    if (second->door.id != 2 || second->door.status != 0) return FAIL;
    
    node* third = add_door(second, door3);
    if (!third || second->next != third) return FAIL;
    if (third->door.id != 3 || third->door.status != 0) return FAIL;
    
    if (root->door.id != 1) return FAIL;
    if (root->next->door.id != 2) return FAIL;
    if (root->next->next->door.id != 3) return FAIL;
    if (root->next->next->next != NULL) return FAIL;
    
    destroy(root);
    return SUCCESS;
}

int test_remove_door() {
    struct door door1 = {1, 0};
    struct door door2 = {2, 0};
    struct door door3 = {3, 0};
    
    node* root = init(door1);
    if (!root) return FAIL;
    
    node* second = add_door(root, door2);
    if (!second) return FAIL;
    
    node* third = add_door(second, door3);
    if (!third) return FAIL;
    
    root = remove_door(second, root);
    if (!root) return FAIL;
    
    if (root->door.id != 1) return FAIL;
    if (root->next->door.id != 3) return FAIL;
    if (root->next->next != NULL) return FAIL;
    
    root = remove_door(third, root);
    if (!root) return FAIL;
    
    if (root->door.id != 1) return FAIL;
    if (root->next != NULL) return FAIL;
    
    root = remove_door(root, root);
    if (root != NULL) return FAIL;
    
    destroy(root);
    return SUCCESS;
}

int test_remove_nonexistent() {
    struct door door1 = {1, 0};
    struct door door2 = {2, 0};
    
    node* root = init(door1);
    if (!root) return FAIL;
    
    node* fake_elem = init(door2);
    
    node* result = remove_door(fake_elem, root);
    
    if (result != root) return FAIL;
    if (root->door.id != 1) return FAIL;
    if (root->next != NULL) return FAIL;
    
    destroy(root);
    free(fake_elem);
    return SUCCESS;
}

int test_add_to_null() {
    struct door door = {1, 0};
    node* result = add_door(NULL, door);
    
    if (result != NULL) return FAIL;
    return SUCCESS;
}

int test_find_door() {
    struct door door1 = {1, 0};
    struct door door2 = {2, 0};
    struct door door3 = {3, 0};
    
    node* root = init(door1);
    if (!root) return FAIL;
    
    add_door(root, door2);
    add_door(root->next, door3);
    
    node* found = find_door(2, root);
    if (!found || found->door.id != 2) return FAIL;
    
    found = find_door(3, root);
    if (!found || found->door.id != 3) return FAIL;
    
    found = find_door(5, root);
    if (found != NULL) return FAIL;
    
    found = find_door(1, NULL);
    if (found != NULL) return FAIL;
    
    destroy(root);
    return SUCCESS;
}

int main() {
    int tests_passed = 0;
    int total_tests = 5;
    
    printf("Running list tests...\n");
    
    if (test_add_door() == SUCCESS) {
        printf("test_add_door: SUCCESS\n");
        tests_passed++;
    } else {
        printf("test_add_door: FAIL\n");
    }
    
    if (test_remove_door() == SUCCESS) {
        printf("test_remove_door: SUCCESS\n");
        tests_passed++;
    } else {
        printf("test_remove_door: FAIL\n");
    }
    
    if (test_remove_nonexistent() == SUCCESS) {
        printf("test_remove_nonexistent: SUCCESS\n");
        tests_passed++;
    } else {
        printf("test_remove_nonexistent: FAIL\n");
    }
    
    if (test_add_to_null() == SUCCESS) {
        printf("test_add_to_null: SUCCESS\n");
        tests_passed++;
    } else {
        printf("test_add_to_null: FAIL\n");
    }
    
    if (test_find_door() == SUCCESS) {
        printf("test_find_door: SUCCESS\n");
        tests_passed++;
    } else {
        printf("test_find_door: FAIL\n");
    }
    
    printf("\nTests passed: %d/%d\n", tests_passed, total_tests);
    
    return (tests_passed == total_tests) ? SUCCESS : FAIL;
}
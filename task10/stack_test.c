#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define SUCCESS 0
#define FAIL 1

int test_stack_init() {
    stack* st = init_stack();
    if (!st) return FAIL;
    
    if (st->top != NULL) {
        destroy_stack(st);
        return FAIL;
    }
    
    if (st->size != 0) {
        destroy_stack(st);
        return FAIL;
    }
    
    destroy_stack(st);
    return SUCCESS;
}

int test_push_pop() {
    stack* st = init_stack();
    if (!st) return FAIL;
    
    if (!push(st, 10)) {
        destroy_stack(st);
        return FAIL;
    }
    
    if (!push(st, 20)) {
        destroy_stack(st);
        return FAIL;
    }
    
    if (!push(st, 30)) {
        destroy_stack(st);
        return FAIL;
    }
    
    if (st->size != 3) {
        destroy_stack(st);
        return FAIL;
    }
    
    int value;
    
    if (!pop(st, &value) || value != 30) {
        destroy_stack(st);
        return FAIL;
    }
    
    if (!pop(st, &value) || value != 20) {
        destroy_stack(st);
        return FAIL;
    }
    
    if (!pop(st, &value) || value != 10) {
        destroy_stack(st);
        return FAIL;
    }
    
    if (st->size != 0 || st->top != NULL) {
        destroy_stack(st);
        return FAIL;
    }
    
    destroy_stack(st);
    return SUCCESS;
}

int test_pop_empty() {
    stack* st = init_stack();
    if (!st) return FAIL;
    
    int value;
    if (pop(st, &value) != 0) {
        destroy_stack(st);
        return FAIL;
    }
    
    destroy_stack(st);
    return SUCCESS;
}

int test_push_null() {
    if (push(NULL, 10) != 0) {
        return FAIL;
    }
    return SUCCESS;
}

int test_pop_null() {
    stack* st = init_stack();
    if (!st) return FAIL;
    
    int value;
    
    if (pop(NULL, &value) != 0) {
        destroy_stack(st);
        return FAIL;
    }

    if (pop(st, NULL) != 0) {
        destroy_stack(st);
        return FAIL;
    }
    
    destroy_stack(st);
    return SUCCESS;
}

int test_multiple_operations() {
    stack* st = init_stack();
    if (!st) return FAIL;
    
    for (int i = 0; i < 100; i++) {
        if (!push(st, i)) {
            destroy_stack(st);
            return FAIL;
        }
    }
    
    if (st->size != 100) {
        destroy_stack(st);
        return FAIL;
    }
    
    for (int i = 99; i >= 50; i--) {
        int value;
        if (!pop(st, &value) || value != i) {
            destroy_stack(st);
            return FAIL;
        }
    }
    
    if (st->size != 50) {
        destroy_stack(st);
        return FAIL;
    }
    
    destroy_stack(st);
    return SUCCESS;
}

int test_after_destroy() {
    stack* st = init_stack();
    if (!st) return FAIL;
    
    push(st, 42);
    destroy_stack(st);
    
    destroy_stack(NULL);
    
    return SUCCESS;
}

int main() {
    int tests_passed = 0;
    int total_tests = 7;
    
    printf("Running stack tests...\n");
    printf("========================\n");
    
    if (test_stack_init() == SUCCESS) {
        printf("test_stack_init: SUCCESS\n");
        tests_passed++;
    } else {
        printf("test_stack_init: FAIL\n");
    }
    
    if (test_push_pop() == SUCCESS) {
        printf("test_push_pop: SUCCESS\n");
        tests_passed++;
    } else {
        printf("test_push_pop: FAIL\n");
    }
    
    if (test_pop_empty() == SUCCESS) {
        printf("test_pop_empty: SUCCESS\n");
        tests_passed++;
    } else {
        printf("test_pop_empty: FAIL\n");
    }
    
    if (test_push_null() == SUCCESS) {
        printf("test_push_null: SUCCESS\n");
        tests_passed++;
    } else {
        printf("test_push_null: FAIL\n");
    }
    
    if (test_pop_null() == SUCCESS) {
        printf("test_pop_null: SUCCESS\n");
        tests_passed++;
    } else {
        printf("test_pop_null: FAIL\n");
    }
    
    if (test_multiple_operations() == SUCCESS) {
        printf("test_multiple_operations: SUCCESS\n");
        tests_passed++;
    } else {
        printf("test_multiple_operations: FAIL\n");
    }
    
    if (test_after_destroy() == SUCCESS) {
        printf("test_after_destroy: SUCCESS\n");
        tests_passed++;
    } else {
        printf("test_after_destroy: FAIL\n");
    }
    
    printf("========================\n");
    printf("Tests passed: %d/%d\n", tests_passed, total_tests);
    
    return (tests_passed == total_tests) ? SUCCESS : FAIL;
}
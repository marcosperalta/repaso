#include <stdio.h>
#include <stdbool.h>
#include "list.h"

void run_test(const char *test_name, bool (*test_func)(), int *score) {
    printf("Running test: %s\n", test_name);
    if (test_func()) {
        printf("Test %s passed\n", test_name);
        (*score)++;
    } else {
        printf("Test %s failed\n", test_name);
    }
}

// Test cases

bool test_empty() {
    list l = empty();
    bool result = is_empty(l);
    destroy(l);
    return result;
}

bool test_addl() {
    list l = empty();
    l = addl(l, 10);
    bool result = !is_empty(l) && head(l) == 10;
    destroy(l);
    return result;
}

bool test_head() {
    list l = empty();
    l = addl(l, 20);
    bool result = head(l) == 20;
    destroy(l);
    return result;
}

bool test_tail() {
    list l = empty();
    l = addl(l, 30);
    l = addl(l, 40);
    l = tail(l);
    bool result = head(l) == 30;
    destroy(l);
    return result;
}

bool test_addr() {
    list l = empty();
    l = addr(l, 50);
    bool result = !is_empty(l) && head(l) == 50;
    destroy(l);
    return result;
}

bool test_length() {
    list l = empty();
    l = addl(l, 10);
    l = addr(l, 20);
    l = addl(l, 30);
    bool result = length(l) == 3;
    destroy(l);
    return result;
}

bool test_concat() {
    list l1 = empty();
    list l2 = empty();
    l1 = addl(l1, 10);
    l2 = addl(l2, 20);
    list l3 = concat(l1, l2);
    bool result = length(l3) == 2 && head(l3) == 10 && head(tail(l3)) == 20;
    destroy(l1);
    destroy(l2);
    destroy(l3);
    return result;
}

bool test_index() {
    list l = empty();
    l = addl(l, 10);
    l = addr(l, 20);
    bool result = index_list(l, 1) == 20;
    destroy(l);
    return result;
}

bool test_take() {
    list l = empty();
    l = addl(l, 10);
    l = addl(l, 20);
    l = addl(l, 30);
    l = take(l, 2);
    bool result = length(l) == 2 && head(l) == 30 && head(tail(l)) == 20;
    destroy(l);
    return result;
}

bool test_drop() {
    list l = empty();
    l = addl(l, 10);
    l = addl(l, 20);
    l = addl(l, 30);
    l = drop(l, 2);
    bool result = length(l) == 1 && head(l) == 10;
    destroy(l);
    return result;
}

bool test_copy_list() {
    list l = empty();
    l = addl(l, 10);
    l = addl(l, 20);
    list l2 = copy_list(l);
    bool result = length(l2) == 2 && head(l2) == 20 && head(tail(l2)) == 10;
    destroy(l);
    destroy(l2);
    return result;
}

bool test_combined_operations() {
    list l = empty();
    l = addl(l, 10);   // [10]
    l = addl(l, 20);   // [20, 10]
    l = addr(l, 30);   // [20, 10, 30]
    l = tail(l);       // [10, 30]
    l = addr(l, 40);   // [10, 30, 40]
    l = addl(l, 50);   // [50, 10, 30, 40]
    l = take(l, 3);    // [50, 10, 30]
    l = drop(l, 1);    // [10, 30]

    bool result = length(l) == 2 && head(l) == 10 && head(tail(l)) == 30;
    destroy(l);
    return result;
}

int main() {
    int score = 0;
    int total_tests = 12;

    run_test("test_empty", test_empty, &score);
    run_test("test_addl", test_addl, &score);
    run_test("test_head", test_head, &score);
    run_test("test_tail", test_tail, &score);
    run_test("test_addr", test_addr, &score);
    run_test("test_length", test_length, &score);
    run_test("test_concat", test_concat, &score);
    run_test("test_index", test_index, &score);
    run_test("test_take", test_take, &score);
    run_test("test_drop", test_drop, &score);
    run_test("test_copy_list", test_copy_list, &score);
    run_test("test_combined_operations", test_combined_operations, &score);

    printf("Tests passed: %d/%d\n", score, total_tests);

    return 0;
}

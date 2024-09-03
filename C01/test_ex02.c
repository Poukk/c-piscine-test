#include "test_helpers.h"

void ft_swap(int *a, int *b);

void cpt_test_exercise() {
    print_exercise("02", "ft_swap");
    int a = 42, b = 24;
    ft_swap(&a, &b);
    char expected[40], actual[40];
    snprintf(expected, sizeof(expected), "a = %d, b = %d", 24, 42);
    snprintf(actual, sizeof(actual), "a = %d, b = %d", a, b);
    compare_output("Test 1: ft_swap(&a, &b)", expected, actual);
}

int main() {
    cpt_test_exercise();
    return 0;
}
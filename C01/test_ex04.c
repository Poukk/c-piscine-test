#include "test_helpers.h"

void ft_ultimate_div_mod(int *a, int *b);

void cpt_test_exercise() {
    print_exercise("04", "ft_ultimate_div_mod");
    int a = 42, b = 10;
    ft_ultimate_div_mod(&a, &b);
    char expected[40], actual[40];
    snprintf(expected, sizeof(expected), "a = %d, b = %d", 4, 2);
    snprintf(actual, sizeof(actual), "a = %d, b = %d", a, b);
    compare_output("Test 1: ft_ultimate_div_mod(&a, &b)", expected, actual);
}

int main() {
    cpt_test_exercise();
    return 0;
}
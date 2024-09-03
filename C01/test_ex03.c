#include "test_helpers.h"

void ft_div_mod(int a, int b, int *div, int *mod);

void cpt_test_exercise() {
    print_exercise("03", "ft_div_mod");
    int a = 42, b = 10, div = 0, mod = 0;
    ft_div_mod(a, b, &div, &mod);
    char expected[40], actual[40];
    snprintf(expected, sizeof(expected), "div = %d, mod = %d", 4, 2);
    snprintf(actual, sizeof(actual), "div = %d, mod = %d", div, mod);
    compare_output("Test 1: ft_div_mod(42, 10, &div, &mod)", expected, actual);
}

int main() {
    cpt_test_exercise();
    return 0;
}
#include "test_helpers.h"

void ft_ft(int *nbr);

void cpt_test_exercise() {
    print_exercise("00", "ft_ft");
    int n = 0;
    ft_ft(&n);
    char expected[20], actual[20];
    snprintf(expected, sizeof(expected), "%d", 42);
    snprintf(actual, sizeof(actual), "%d", n);
    compare_output("Test 1: ft_ft(&n)", expected, actual);
}

int main() {
    cpt_test_exercise();
    return 0;
}
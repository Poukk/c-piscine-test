#include "test_helpers.h"

void ft_is_negative(int n);

void cpt_test_exercise() {
    print_exercise("04", "ft_is_negative");
    printstr("Test 1: ft_is_negative(42)\n");
    printstr("Expected output: P\n");
    printstr("Actual output  : ");
    ft_is_negative(42);
    printstr("\n\n");

    printstr("Test 2: ft_is_negative(-42)\n");
    printstr("Expected output: N\n");
    printstr("Actual output  : ");
    ft_is_negative(-42);
    printstr("\n\n");

    printstr("Test 1: ft_is_negative(0)\n");
    printstr("Expected output: P\n");
    printstr("Actual output  : ");
    ft_is_negative(0);
    printstr("\n\n");
}

int main() {
    cpt_test_exercise();
    return 0;
}
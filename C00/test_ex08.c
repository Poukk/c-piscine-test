#include "test_helpers.h"

void ft_print_combn(int n);

void cpt_test_exercise() {
    print_exercise("08", "ft_print_combn");
    printstr("Test 1: ft_print_combn(1)\n");
    printstr("Expected output: 01, 02, 03, 04, 05, 06, 07, 08, 09, 12, 13, 14, 15, 16, 17, 18, 19, 23, 24, 25, 26, 27, 28, 29, 34, 35, 36, 37, 38, 39, 45, 46, 47, 48, 49, 56, 57, 58, 59, 67, 68, 69, 78, 79, 89\n");
    printstr("Actual output  : ");
    ft_print_combn(2);
    printf("\n");
}

int main() {
    cpt_test_exercise();
    return 0;
}
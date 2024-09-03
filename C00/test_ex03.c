#include "test_helpers.h"

void ft_print_numbers(void);

void cpt_test_exercise() {
    print_exercise("03", "ft_print_numbers");

    printstr("Test 1: ft_print_numbers()\n");
    printstr("Expected output: 0123456789\n");
    printstr("Actual output  : ");
    ft_print_numbers();
    printstr("\n\n");
}

int main() {
    cpt_test_exercise();
    return 0;
}
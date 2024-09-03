#include "test_helpers.h"

void ft_putchar(char c);

void cpt_test_exercise() {
    print_exercise("00", "ft_putchar");

    printstr("Test 1: ft_putchar('A')\n");
    printstr("Expected output: A\n");
    printstr("Actual output  : ");
    ft_putchar('A');
    write(1, "\n\n", 2);
}

int main() {
    cpt_test_exercise();
    return 0;
}
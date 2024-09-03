#include "test_helpers.h"

void ft_putnbr(int nb);

void cpt_test_exercise() {
    print_exercise("07", "ft_putnbr");
    printstr("Test 1: ft_putnbr(42)\n");
    printstr("Expected output: 42\n");
    printstr("Actual output  : ");
    ft_putnbr(42);
    printstr("\n\n");

    printstr("Test 2: ft_putnbr(-42)\n");
    printstr("Expected output: -42\n");
    printstr("Actual output  : ");
    ft_putnbr(-42);
    printstr("\n\n");

    printstr("Test 3: ft_putnbr(2147483647)\n");
    printstr("Expected output: 2147483647\n");
    printstr("Actual output  : ");
    ft_putnbr(2147483647);
    printstr("\n\n");

    printstr("Test 4: ft_putnbr(-2147483648)\n");
    printstr("Expected output: -2147483648\n");
    printstr("Actual output  : ");
    ft_putnbr(-2147483648);
    printstr("\n\n");
}

int main() {
    cpt_test_exercise();
    return 0;
}
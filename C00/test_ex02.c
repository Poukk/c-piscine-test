#include "test_helpers.h"

void ft_print_reverse_alphabet(void);

void cpt_test_exercise() {
    print_exercise("02", "ft_print_reverse_alphabet");

    printstr("Test 1: ft_print_reverse_alphabet()\n");
    printstr("Expected output: zyxwvutsrqponmlkjihgfedcba\n");
    printstr("Actual output  : ");
    ft_print_reverse_alphabet();
    write(1, "\n\n", 2);
}

int main() {
    cpt_test_exercise();
    return 0;
}
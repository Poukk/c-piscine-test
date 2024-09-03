#include "test_helpers.h"

void ft_putstr_non_printable(char *str);

void cpt_test_exercise() {
    print_exercise("11", "ft_putstr_non_printable");
    char str[] = "Coucou\ntu vas bien ?";
    write(1, "Test 1: ft_putstr_non_printable(\"Coucou\\ntu vas bien ?\")\n", 57);
    write(1, "Expected output: Coucou\\0atu vas bien ?\n", 40);
    write(1, "Actual output  : ", 17);
    ft_putstr_non_printable(str);
    write(1, "\n\n", 2);
}

int main() {
    cpt_test_exercise();
    return 0;
}
#include "test_helpers.h"

void ft_putstr(char *str);

void cpt_test_exercise() {
    print_exercise("05", "ft_putstr");
    char str[] = "Hello, World!";
    write(1, "Test 1: ft_putstr(\"Hello, World!\")\n", 36);
    write(1, "Expected output: Hello, World!\n", 31);
    write(1, "Actual output  : ", 17);
    ft_putstr(str);
    write(1, "\n\n", 2);
}

int main() {
    cpt_test_exercise();
    return 0;
}
#include "test_helpers.h"

void ft_putstr(char *str);

void cpt_test_exercise()     {
    print_exercise("01", "ft_putstr");
    printf("%s%s This test requires manual verification.%s\n", YELLOW, INFO, RESET);

    char *tests_str[] = {"Hello, World!", "Test\tspace", "\0"};
    for (int i = 0; i < 3; i++) {
        printf("Test %d: ft_putnbr(%s)\n", i + 1, tests_str[i]);
        printf("Expected output: %s\n", tests_str[i]);
        printstr("Actual output  : ");
        ft_putstr(tests_str[i]);
        printf("\n\n");
    }
}

int main() {
    cpt_test_exercise();
    return 0;
}

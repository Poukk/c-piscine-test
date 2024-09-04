#include "test_helpers.h"

void ft_putnbr(int nb);

void cpt_test_exercise() {
    print_exercise("02", "ft_putnbr");
    printf("%s%s This test requires manual verification.%s\n", YELLOW, INFO, RESET);
    int test_numbers[] = {42, 0, -42, 2147483647, -2147483648};
    int num_tests = sizeof(test_numbers) / sizeof(test_numbers[0]);

    for (int i = 0; i < num_tests; i++) {
        printf("Test %d: ft_putnbr(%d)\n", i + 1, test_numbers[i]);
        printf("Expected output: %d\n", test_numbers[i]);
        printstr("Actual output  : ");
        ft_putnbr(test_numbers[i]);
        printf("\n\n");
    }
}

int main() {
    cpt_test_exercise();
    return 0;
}

#include "test_helpers.h"

void ft_putnbr_base(int nbr, char *base);

void cpt_test_exercise() {
    print_exercise("04", "ft_putnbr_base");
    int test_numbers[] = {42, -42, 2147483647, -2147483648};
    char *test_bases[] = {"0123456789", "01", "0123456789ABCDEF", "poneyvif"};
    int num_tests = sizeof(test_numbers) / sizeof(test_numbers[0]);

    for (int i = 0; i < num_tests; i++) {
        for (int j = 0; j < 4; j++) {
            printf("Test %d.%d: ft_putnbr_base(%d, \"%s\")\n", i + 1, j + 1, test_numbers[i], test_bases[j]);
            printf("Actual output: ");
            ft_putnbr_base(test_numbers[i], test_bases[j]);
            printf("\n\n");
        }
    }
}

int main() {
    cpt_test_exercise();
    return 0;
}

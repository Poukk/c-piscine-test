#include "test_helpers.h"

int ft_recursive_power(int nb, int power);

int int_pow(int base, int exp) {
    int result = 1;
    while (exp) {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }
    return result;
}

void cpt_test_exercise() {
    print_exercise("03", "ft_recursive_power");
    int test_numbers[] = {0, 1, 5, 10, 12};
    int num_tests = sizeof(test_numbers) / sizeof(test_numbers[0]);

    srand(time(NULL));

    for (int i = 0; i < num_tests; i++) {
        int nb = test_numbers[i];
        int power = rand() % 6;
        
        char expected[21], actual[21];
        
        snprintf(expected, sizeof(expected), "%d", int_pow(nb, power));
        snprintf(actual, sizeof(actual), "%d", ft_recursive_power(nb, power));
        
        char test_name[50];
        snprintf(test_name, sizeof(test_name), "Test %d: ft_recursive_power(%d, %d)", i + 1, nb, power);
        
        compare_output(test_name, expected, actual);
    }
}

int main() {
    cpt_test_exercise();
    return 0;
}
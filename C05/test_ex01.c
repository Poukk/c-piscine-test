#include "test_helpers.h"

int ft_recursive_factorial(int nb);

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

void cpt_test_exercise() {
    print_exercise("01", "ft_recursive_factorial");
    int test_numbers[] = {0, 1, 5, 10, 12};
    int num_tests = sizeof(test_numbers) / sizeof(test_numbers[0]);

    for (int i = 0; i < num_tests; i++) {
        int n = test_numbers[i];
        char expected[21], actual[21];
        
        snprintf(expected, sizeof(expected), "%d", factorial(n));
        
        snprintf(actual, sizeof(actual), "%d", ft_recursive_factorial(n));
        
        char test_name[50];
        snprintf(test_name, sizeof(test_name), "Test %d: ft_recursive_factorial(%d)", i + 1, n);
        
        compare_output(test_name, expected, actual);
    }
}

int main() {
    cpt_test_exercise();
    return 0;
}
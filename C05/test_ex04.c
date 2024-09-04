#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "test_helpers.h"

int ft_fibonacci(int index);

int fibonacci(int n) {
    if (n < 0) return -1;
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void cpt_test_exercise() {
    print_exercise("02", "ft_fibonacci");
    int test_indices[] = {-1, 0, 3,  8, 15};
    int num_tests = sizeof(test_indices) / sizeof(test_indices[0]);

    for (int i = 0; i < num_tests; i++) {
        int index = test_indices[i];
        
        char expected[21], actual[21];
        
        snprintf(expected, sizeof(expected), "%d", fibonacci(index));
        snprintf(actual, sizeof(actual), "%d", ft_fibonacci(index));
        
        char test_name[50];
        snprintf(test_name, sizeof(test_name), "Test %d: ft_fibonacci(%d)", i + 1, index);
        
        compare_output(test_name, expected, actual);
    }
}

int main() {
    cpt_test_exercise();
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "test_helpers.h"

int ft_find_next_prime(int nb);

int is_prime(int n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}

int find_next_prime_ref(int nb) {
    if (nb <= 2) return 2;
    int next = nb;
    if (next % 2 == 0) next++;
    while (!is_prime(next)) {
        next += 2;
    }
    return next;
}

void cpt_test_exercise() {
    print_exercise("05", "ft_find_next_prime");
    int test_numbers[] = {-10, 0, 1, 18, 29, 2147483629};
    int num_tests = sizeof(test_numbers) / sizeof(test_numbers[0]);

    for (int i = 0; i < num_tests; i++) {
        int nb = test_numbers[i];
        
        char expected[21], actual[21];
        
        snprintf(expected, sizeof(expected), "%d", find_next_prime_ref(nb));
        snprintf(actual, sizeof(actual), "%d", ft_find_next_prime(nb));
        
        char test_name[50];
        snprintf(test_name, sizeof(test_name), "Test %d: ft_find_next_prime(%d)", i + 1, nb);
        
        compare_output(test_name, expected, actual);
    }
}

int main() {
    cpt_test_exercise();
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "test_helpers.h"

int ft_is_prime(int nb);

int is_prime_ref(int nb) {
    if (nb <= 1) return 0;
    if (nb <= 3) return 1;
    if (nb % 2 == 0 || nb % 3 == 0) return 0;
    
    for (int i = 5; i * i <= nb; i += 6) {
        if (nb % i == 0 || nb % (i + 2) == 0) return 0;
    }
    return 1;
}

void cpt_test_exercise() {
    print_exercise("04", "ft_is_prime");
    int test_numbers[] = {-1, 0, 1, 2, 3, 4, 9, 15, 19, 20, 97};
    int num_tests = sizeof(test_numbers) / sizeof(test_numbers[0]);

    for (int i = 0; i < num_tests; i++) {
        int nb = test_numbers[i];
        
        char expected[21], actual[21];
        
        snprintf(expected, sizeof(expected), "%d", is_prime_ref(nb));
        snprintf(actual, sizeof(actual), "%d", ft_is_prime(nb));
        
        char test_name[50];
        snprintf(test_name, sizeof(test_name), "Test %d: ft_is_prime(%d)", i + 1, nb);
        
        compare_output(test_name, expected, actual);
    }
}

int main() {
    cpt_test_exercise();
    return 0;
}
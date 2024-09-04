#include <stdio.h>
#include <stdlib.h>
#include "test_helpers.h"

int ft_sqrt(int nb);

int sqrt_ref(int nb) {
    if (nb < 0) return 0;
    if (nb == 0 || nb == 1) return nb;
    
    int left = 1, right = nb;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (mid == nb / mid && nb % mid == 0) return mid;
        if (mid <= nb / mid) left = mid + 1;
        else right = mid - 1;
    }
    return 0;
}

void cpt_test_exercise() {
    print_exercise("03", "ft_sqrt");
    int test_numbers[] = {-4, 0, 1, 3, 25, 81, 100};
    int num_tests = sizeof(test_numbers) / sizeof(test_numbers[0]);

    for (int i = 0; i < num_tests; i++) {
        int nb = test_numbers[i];
        
        char expected[21], actual[21];
        
        snprintf(expected, sizeof(expected), "%d", sqrt_ref(nb));
        snprintf(actual, sizeof(actual), "%d", ft_sqrt(nb));
        
        char test_name[50];
        snprintf(test_name, sizeof(test_name), "Test %d: ft_sqrt(%d)", i + 1, nb);
        
        compare_output(test_name, expected, actual);
    }
}

int main() {
    cpt_test_exercise();
    return 0;
}
#include "test_helpers.h"

int ft_str_is_lowercase(char *str);

void cpt_test_exercise() {
    print_exercise("04", "ft_str_is_lowercase");
    char expected[20], actual[20];
    snprintf(expected, sizeof(expected), "%d", 1);
    snprintf(actual, sizeof(actual), "%d", ft_str_is_lowercase("hello"));
    compare_output("Test 1: ft_str_is_lowercase(\"hello\")", expected, actual);
    
    snprintf(expected, sizeof(expected), "%d", 0);
    snprintf(actual, sizeof(actual), "%d", ft_str_is_lowercase("Hello"));
    compare_output("Test 2: ft_str_is_lowercase(\"Hello\")", expected, actual);
}

int main() {
    cpt_test_exercise();
    return 0;
}
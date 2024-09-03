#include "test_helpers.h"

int ft_str_is_uppercase(char *str);

void cpt_test_exercise() {
    print_exercise("05", "ft_str_is_uppercase");
    char expected[20], actual[20];
    snprintf(expected, sizeof(expected), "%d", 1);
    snprintf(actual, sizeof(actual), "%d", ft_str_is_uppercase("HELLO"));
    compare_output("Test 1: ft_str_is_uppercase(\"HELLO\")", expected, actual);
    
    snprintf(expected, sizeof(expected), "%d", 0);
    snprintf(actual, sizeof(actual), "%d", ft_str_is_uppercase("HELLo"));
    compare_output("Test 2: ft_str_is_uppercase(\"HELLo\")", expected, actual);
}

int main() {
    cpt_test_exercise();
    return 0;
}
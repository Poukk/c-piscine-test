#include "test_helpers.h"

int ft_str_is_alpha(char *str);

void cpt_test_exercise() {
    print_exercise("02", "ft_str_is_alpha");
    char expected[20], actual[20];
    snprintf(expected, sizeof(expected), "%d", 1);
    snprintf(actual, sizeof(actual), "%d", ft_str_is_alpha("HelloWorld"));
    compare_output("Test 1: ft_str_is_alpha(\"HelloWorld\")", expected, actual);
    
    snprintf(expected, sizeof(expected), "%d", 0);
    snprintf(actual, sizeof(actual), "%d", ft_str_is_alpha("Hello, World!"));
    compare_output("Test 2: ft_str_is_alpha(\"Hello, World!\")", expected, actual);
}

int main() {
    cpt_test_exercise();
    return 0;
}
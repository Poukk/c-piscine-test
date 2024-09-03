#include "test_helpers.h"

int ft_str_is_numeric(char *str);

void cpt_test_exercise() {
    print_exercise("03", "ft_str_is_numeric");
    char expected[20], actual[20];
    snprintf(expected, sizeof(expected), "%d", 1);
    snprintf(actual, sizeof(actual), "%d", ft_str_is_numeric("12345"));
    compare_output("Test 1: ft_str_is_numeric(\"12345\")", expected, actual);
    
    snprintf(expected, sizeof(expected), "%d", 0);
    snprintf(actual, sizeof(actual), "%d", ft_str_is_numeric("123abc"));
    compare_output("Test 2: ft_str_is_numeric(\"123abc\")", expected, actual);
}

int main() {
    cpt_test_exercise();
    return 0;
}
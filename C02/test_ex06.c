#include "test_helpers.h"

int ft_str_is_printable(char *str);

void cpt_test_exercise() {
    print_exercise("06", "ft_str_is_printable");
    char expected[20], actual[20];
    snprintf(expected, sizeof(expected), "%d", 1);
    snprintf(actual, sizeof(actual), "%d", ft_str_is_printable("Hello, World!"));
    compare_output("Test 1: ft_str_is_printable(\"Hello, World!\")", expected, actual);
    
    char str_with_non_printable[] = "Hello\nWorld";
    snprintf(expected, sizeof(expected), "%d", 0);
    snprintf(actual, sizeof(actual), "%d", ft_str_is_printable(str_with_non_printable));
    compare_output("Test 2: ft_str_is_printable(\"Hello\\nWorld\")", expected, actual);
}

int main() {
    cpt_test_exercise();
    return 0;
}
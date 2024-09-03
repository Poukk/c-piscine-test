#include "test_helpers.h"

int ft_strlen(char *str);

void cpt_test_exercise() {
    print_exercise("06", "ft_strlen");
    char str[] = "Hello, World!";
    int len = ft_strlen(str);
    char expected[20], actual[20];
    snprintf(expected, sizeof(expected), "%d", 13);
    snprintf(actual, sizeof(actual), "%d", len);
    compare_output("Test 1: ft_strlen(\"Hello, World!\")", expected, actual);
}

int main() {
    cpt_test_exercise();
    return 0;
}
#include "test_helpers.h"

int ft_atoi(char *str);

void cpt_test_exercise() {
    print_exercise("03", "ft_atoi");
    char *test_strings[] = {"42", "  -42", " ---+--+1234ab567", "2147483647", "-2147483648"};
    int num_tests = sizeof(test_strings) / sizeof(test_strings[0]);

    for (int i = 0; i < num_tests; i++) {
        char expected[20], actual[20];
        snprintf(expected, sizeof(expected), "%d", atoi(test_strings[i]));
        snprintf(actual, sizeof(actual), "%d", ft_atoi(test_strings[i]));
        char test_name[50];
        snprintf(test_name, sizeof(test_name), "Test %d: ft_atoi(\"%s\")", i + 1, test_strings[i]);
        compare_output(test_name, expected, actual);
    }
}

int main() {
    cpt_test_exercise();
    return 0;
}

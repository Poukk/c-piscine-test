#include "test_helpers.h"

int ft_strlen(char *str);

void cpt_test_exercise() {
    print_exercise("00", "ft_strlen");
    char *test_strings[] = {"Hello", "", "This is a long string", "12345"};
    int num_tests = sizeof(test_strings) / sizeof(test_strings[0]);

    for (int i = 0; i < num_tests; i++) {
        char expected[20], actual[20];
        snprintf(expected, sizeof(expected), "%lu", strlen(test_strings[i]));
        snprintf(actual, sizeof(actual), "%d", ft_strlen(test_strings[i]));
        char test_name[50];
        snprintf(test_name, sizeof(test_name), "Test %d: ft_strlen(\"%s\")", i + 1, test_strings[i]);
        compare_output(test_name, expected, actual);
    }
}

int main() {
    cpt_test_exercise();
    return 0;
}

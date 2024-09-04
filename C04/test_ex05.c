#include "test_helpers.h"

int ft_atoi_base(char *str, char *base);

void cpt_test_exercise() {
    print_exercise("05", "ft_atoi_base");
    char *test_strings[] = {"42", "-42", "10", "2A"};
    char *test_bases[] = {"0123456789", "01", "0123456789ABCDEF", "poneyvif"};
    int num_tests = sizeof(test_strings) / sizeof(test_strings[0]);

    for (int i = 0; i < num_tests; i++) {
        for (int j = 0; j < 4; j++) {
            char test_name[100];
            snprintf(test_name, sizeof(test_name), "Test %d.%d: ft_atoi_base(\"%s\", \"%s\")", i + 1, j + 1, test_strings[i], test_bases[j]);
            char actual[20];
            snprintf(actual, sizeof(actual), "%d", ft_atoi_base(test_strings[i], test_bases[j]));
            compare_output(test_name, "Manual verification required", actual);
        }
    }
}

int main() {
    cpt_test_exercise();
    return 0;
}

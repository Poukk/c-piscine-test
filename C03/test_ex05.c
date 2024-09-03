#include "test_helpers.h"

unsigned int ft_strlcat(char *dest, char *src, unsigned int size);

void cpt_test_exercise() {
    print_exercise("05", "ft_strlcat");
    char dest5[20] = "Hello";
    char src5[] = " World";
    char dest5_std[20] = "Hello";
    char dest6[10] = "Hello";
    char src6[] = " World";
    char dest6_std[10] = "Hello";

    char expected[40], actual[40];

    size_t res_std = strlcat(dest5_std, src5, 20);
    size_t res_ft = ft_strlcat(dest5, src5, 20);
    snprintf(expected, sizeof(expected), "%zu - %s", res_std, dest5_std);
    snprintf(actual, sizeof(actual), "%lu - %s", res_ft, dest5);
    compare_output("Test 1: ft_strlcat(\"Hello\", \" World\", 20)", expected, actual);

    res_std = strlcat(dest6_std, src6, 10);
    res_ft = ft_strlcat(dest6, src6, 10);
    snprintf(expected, sizeof(expected), "%zu - %s", res_std, dest6_std);
    snprintf(actual, sizeof(actual), "%lu - %s", res_ft, dest6);
    compare_output("Test 2: ft_strlcat(\"Hello\", \" World\", 10)", expected, actual);
}

int main() {
    cpt_test_exercise();
    return 0;
}
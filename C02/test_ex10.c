#include "test_helpers.h"

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);

void cpt_test_exercise() {
    print_exercise("10", "ft_strlcpy");
    char src[] = "Hello, World!";
    char dest[20];
    unsigned int size = ft_strlcpy(dest, src, sizeof(dest));
    char expected[40], actual[40];
    snprintf(expected, sizeof(expected), "dest: \"Hello, World!\", size: 13");
    snprintf(actual, sizeof(actual), "dest: \"%s\", size: %u", dest, size);
    compare_output("Test 1: ft_strlcpy()", expected, actual);
}

int main() {
    cpt_test_exercise();
    return 0;
}
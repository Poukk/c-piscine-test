#include "test_helpers.h"

int ft_strncmp(char *s1, char *s2, unsigned int n);

void cpt_test_exercise() {
    print_exercise("01", "ft_strncmp");
    char s1[] = "Hello";
    char s2[] = "Hello World";
    char s3[] = "Hell";

    char expected[20], actual[20];

    snprintf(expected, sizeof(expected), "%d", strncmp(s1, s2, 3));
    snprintf(actual, sizeof(actual), "%d", ft_strncmp(s1, s2, 3));
    compare_output("Test 1: ft_strncmp(\"Hello\", \"Hello World\", 3)", expected, actual);

    snprintf(expected, sizeof(expected), "%d", strncmp(s1, s3, 5));
    snprintf(actual, sizeof(actual), "%d", ft_strncmp(s1, s3, 5));
    compare_output("Test 2: ft_strncmp(\"Hello\", \"Hell\", 5)", expected, actual);
}

int main() {
    cpt_test_exercise();
    return 0;
}
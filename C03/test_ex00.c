#include "test_helpers.h"

int ft_strcmp(char *s1, char *s2);

void cpt_test_exercise() {
    print_exercise("00", "ft_strcmp");
    char s1[] = "Hello";
    char s2[] = "Hello";
    char s3[] = "World";
    char s4[] = "";
    char s5[] = "HelLo";

    char expected[20], actual[20];

    snprintf(expected, sizeof(expected), "%d", strcmp(s1, s2));
    snprintf(actual, sizeof(actual), "%d", ft_strcmp(s1, s2));
    compare_output("Test 1: ft_strcmp(\"Hello\", \"Hello\")", expected, actual);

    snprintf(expected, sizeof(expected), "%d", strcmp(s1, s3));
    snprintf(actual, sizeof(actual), "%d", ft_strcmp(s1, s3));
    compare_output("Test 2: ft_strcmp(\"Hello\", \"World\")", expected, actual);

    snprintf(expected, sizeof(expected), "%d", strcmp(s1, s4));
    snprintf(actual, sizeof(actual), "%d", ft_strcmp(s1, s4));
    compare_output("Test 3: ft_strcmp(\"Hello\", \"\")", expected, actual);

    snprintf(expected, sizeof(expected), "%d", strcmp(s1, s5));
    snprintf(actual, sizeof(actual), "%d", ft_strcmp(s1, s5));
    compare_output("Test 4: ft_strcmp(\"Hello\", \"HelLo\")", expected, actual);
}

int main() {
    cpt_test_exercise();
    return 0;
}
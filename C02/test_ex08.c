#include "test_helpers.h"

char *ft_strlowcase(char *str);

void cpt_test_exercise() {
    print_exercise("08", "ft_strlowcase");
    char str[] = "Hello, World!";
    ft_strlowcase(str);
    compare_output("Test 1: ft_strlowcase(\"Hello, World!\")", "hello, world!", str);
}

int main() {
    cpt_test_exercise();
    return 0;
}
#include "test_helpers.h"

char *ft_strupcase(char *str);

void cpt_test_exercise() {
    print_exercise("07", "ft_strupcase");
    char str[] = "Hello, World!";
    ft_strupcase(str);
    compare_output("Test 1: ft_strupcase(\"Hello, World!\")", "HELLO, WORLD!", str);
}

int main() {
    cpt_test_exercise();
    return 0;
}
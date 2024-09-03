#include "test_helpers.h"

char *ft_strncpy(char *dest, char *src, unsigned int n);

void cpt_test_exercise() {
    print_exercise("01", "ft_strncpy");
    char src[] = "Hello, World!";
    char dest[20] = {0};
    ft_strncpy(dest, src, 5);
    compare_output("Test 1: ft_strncpy(dest, \"Hello, World!\", 5)", "Hello", dest);
}

int main() {
    cpt_test_exercise();
    return 0;
}
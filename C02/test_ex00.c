#include "test_helpers.h"

char *ft_strcpy(char *dest, char *src);

void cpt_test_exercise() {
    print_exercise("00", "ft_strcpy");
    char src[] = "Hello, World!";
    char dest[20];
    ft_strcpy(dest, src);
    compare_output("Test 1: ft_strcpy(dest, \"Hello, World!\")", src, dest);
}

int main() {
    cpt_test_exercise();
    return 0;
}
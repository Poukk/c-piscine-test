#include "test_helpers.h"

char *ft_strncat(char *dest, char *src, unsigned int nb);

void cpt_test_exercise() {
    print_exercise("03", "ft_strncat");
    char dest3[20] = "Hello";
    char src3[] = " World";
    char dest3_std[20] = "Hello";
    char dest4[20] = "";
    char src4[] = "Hello";
    char dest4_std[20] = "";

    strncat(dest3_std, src3, 3);
    ft_strncat(dest3, src3, 3);
    compare_output("Test 1: ft_strncat(\"Hello\", \" World\", 3)", dest3_std, dest3);

    strncat(dest4_std, src4, 5);
    ft_strncat(dest4, src4, 5);
    compare_output("Test 2: ft_strncat(\"\", \"Hello\", 5)", dest4_std, dest4);
}

int main() {
    cpt_test_exercise();
    return 0;
}
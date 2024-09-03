#include "test_helpers.h"

char *ft_strcat(char *dest, char *src);

void cpt_test_exercise() {
    print_exercise("02", "ft_strcat");
    char dest1[20] = "Hello";
    char src1[] = " World";
    char dest1_std[20] = "Hello";
    char dest2[20] = "";
    char src2[] = "Hello";
    char dest2_std[20] = "";

    strcat(dest1_std, src1);
    ft_strcat(dest1, src1);
    compare_output("Test 1: ft_strcat(\"Hello\", \" World\")", dest1_std, dest1);

    strcat(dest2_std, src2);
    ft_strcat(dest2, src2);
    compare_output("Test 2: ft_strcat(\"\", \"Hello\")", dest2_std, dest2);
}

int main() {
    cpt_test_exercise();
    return 0;
}
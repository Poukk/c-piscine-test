#include "test_helpers.h"

void ft_ultimate_ft(int *********nbr);

void cpt_test_exercise() {
    print_exercise("01", "ft_ultimate_ft");
    int n = 0;
    int *p1 = &n;
    int **p2 = &p1;
    int ***p3 = &p2;
    int ****p4 = &p3;
    int *****p5 = &p4;
    int ******p6 = &p5;
    int *******p7 = &p6;
    int ********p8 = &p7;
    int *********p9 = &p8;
    ft_ultimate_ft(p9);
    char expected[20], actual[20];
    snprintf(expected, sizeof(expected), "%d", 42);
    snprintf(actual, sizeof(actual), "%d", n);
    compare_output("Test 1: ft_ultimate_ft(p9)", expected, actual);
}

int main() {
    cpt_test_exercise();
    return 0;
}
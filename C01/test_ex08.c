#include "test_helpers.h"

void ft_sort_int_tab(int *tab, int size);

void cpt_test_exercise() {
    print_exercise("08", "ft_sort_int_tab");
    int tab[] = {5, 2, 8, 1, 9};
    int size = 5;
    ft_sort_int_tab(tab, size);
    char expected[40], actual[40];
    snprintf(expected, sizeof(expected), "1 2 5 8 9");
    snprintf(actual, sizeof(actual), "%d %d %d %d %d", tab[0], tab[1], tab[2], tab[3], tab[4]);
    compare_output("Test 1: ft_sort_int_tab({5, 2, 8, 1, 9}, 5)", expected, actual);
}

int main() {
    cpt_test_exercise();
    return 0;
}
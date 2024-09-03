#include "test_helpers.h"

void ft_print_comb2(void);

void cpt_test_exercise() {
    print_exercise("06", "ft_print_comb2");
    printstr("Test 1: ft_print_comb2()\n");
    printstr("Expected output: 00 01, 00 02, 00 03, 00 04, 00 05, ..., 00 99, 01 02, ..., 97 99, 98 99\n");
    printstr("Actual output: ");
    ft_print_comb2();
    printstr("\n\n");
}

int main() {
    cpt_test_exercise();
    return 0;
}
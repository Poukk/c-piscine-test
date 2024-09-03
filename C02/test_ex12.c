#include "test_helpers.h"

void *ft_print_memory(void *addr, unsigned int size);

void cpt_test_exercise() {
    print_exercise("12", "ft_print_memory");
    char str[] = "Bonjour les aminches\t\n\tc  est fou\ttout\tce qu on peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n ";
    write(1, "Test 1: ft_print_memory(str, sizeof(str))\n", 42);
    write(1, "Expected output: (see subject for exact format)\n", 48);
    write(1, "Actual output  :\n", 17);
    ft_print_memory(str, sizeof(str));
    write(1, "\n", 1);
}

int main() {
    cpt_test_exercise();
    return 0;
}
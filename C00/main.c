#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

void print_exercise(char *exercise, char *function) {
    int total_width = 80;
    int prefix_suffix_width = 7;
    int text_length = strlen(exercise) + strlen(function) + 11;

    int padding = (total_width - text_length) / 2 - prefix_suffix_width;
    int left_padding = padding > 0 ? padding : 0;
    int right_padding = total_width - text_length - left_padding - (2 * prefix_suffix_width);

    printf("=======");
    for (int i = 0; i < left_padding; i++) printf("=");
    printf("Exercise %s: %s", exercise, function);
    for (int i = 0; i < right_padding; i++) printf("=");
    printf("=======\n");
}

void printstr(char *str) {
    while(*str) {
      write(1, str, 1);
      str++;
    }
}

#ifdef EX00
void ft_putchar(char c);
#endif

#ifdef EX01
void ft_print_alphabet(void);
#endif

#ifdef EX02
void ft_print_reverse_alphabet(void);
#endif

#ifdef EX03
void ft_print_numbers(void);
#endif

#ifdef EX04
void ft_is_negative(int n);
#endif

#ifdef EX05
void ft_print_comb(void);
#endif

#ifdef EX06
void ft_print_comb2(void);
#endif

#ifdef EX07
void ft_putnbr(int nb);
#endif

#ifdef EX08
void ft_print_combn(int n);
#endif

#ifdef EX00
void test_ex00() {
    print_exercise("00", "ft_putchar");
    printstr("Test 1: ft_putchar('A')\n");
    printstr("Expected output: A\n");
    printstr("Actual output  : ");
    ft_putchar('A');
    write(1, "\n\n", 2);
}
#endif

#ifdef EX01
void test_ex01() {
    print_exercise("01", "ft_print_alphabet");
    printstr("Test 1: ft_print_alphabet()\n");
    printstr("Expected output: abcdefghijklmnopqrstuvwxyz\n");
    printstr("Actual output  : ");
    ft_print_alphabet();
    write(1, "\n\n", 2);
}
#endif

#ifdef EX02
void test_ex02() {
    print_exercise("02", "ft_print_reverse_alphabet");
    printstr("Test 1: ft_print_reverse_alphabet()\n");
    printstr("Expected output: zyxwvutsrqponmlkjihgfedcba\n");
    printstr("Actual output  : ");
    ft_print_reverse_alphabet();
    write(1, "\n\n", 2);
}
#endif

#ifdef EX03
void test_ex03() {
    print_exercise("03", "ft_print_numbers");
    printstr("Test 1: ft_print_numbers()\n");
    printstr("Expected output: 0123456789\n");
    printstr("Actual output  : ");
    ft_print_numbers();
    printstr("\n\n");
}
#endif

#ifdef EX04
void test_ex04() {
    print_exercise("04", "ft_is_negative");
    printstr("Test 1: ft_is_negative(42)\n");
    printstr("Expected output: P\n");
    printstr("Actual output  : ");
    ft_is_negative(42);
    printstr("\n\n");

    printstr("Test 2: ft_is_negative(-42)\n");
    printstr("Expected output: N\n");
    printstr("Actual output  : ");
    ft_is_negative(-42);
    printstr("\n\n");

    printstr("Test 1: ft_is_negative(0)\n");
    printstr("Expected output: P\n");
    printstr("Actual output  : ");
    ft_is_negative(0);
    printstr("\n\n");
}
#endif

#ifdef EX05
void test_ex05() {
    print_exercise("05", "ft_print_comb");
    printstr("Test 1: ft_print_comb()\n");
    printstr("Expected output: 012, 013, 014, 015, 016, 017, 018, 019, 023, 024, 025, 026, 027, 028, 029, 034, 035, 036, 037, 038, 039, 045, 046, 047, 048, 049, 056, 057, 058, 059, 067, 068, 069, 078, 079, 089, 123, 124, 125, 126, 127, 128, 129, 134, 135, 136, 137, 138, 139, 145, 146, 147, 148, 149, 156, 157, 158, 159, 167, 168, 169, 178, 179, 189, 234, 235, 236, 237, 238, 239, 245, 246, 247, 248, 249, 256, 257, 258, 259, 267, 268, 269, 278, 279, 289, 345, 346, 347, 348, 349, 356, 357, 358, 359, 367, 368, 369, 378, 379, 389, 456, 457, 458, 459, 467, 468, 469, 478, 479, 489, 567, 568, 569, 578, 579, 589, 678, 679, 689, 789\n");
    printstr("Actual output  : ");
    ft_print_comb();
    printstr("\n\n");
}
#endif

#ifdef EX06
void test_ex06() {
    print_exercise("06", "ft_print_comb2");
    printstr("Test 1: ft_print_comb2()\n");
    printstr("Expected output: 00 01, 00 02, 00 03, 00 04, 00 05, ..., 00 99, 01 02, ..., 97 99, 98 99\n");
    printstr("Actual output: ");
    ft_print_comb2();
    printstr("\n\n");
}
#endif

#ifdef EX07
void test_ex07() {
    print_exercise("07", "ft_putnbr");
    printstr("Test 1: ft_putnbr(42)\n");
    printstr("Expected output: 42\n");
    printstr("Actual output  : ");
    ft_putnbr(42);
    printstr("\n\n");

    printstr("Test 2: ft_putnbr(-42)\n");
    printstr("Expected output: -42\n");
    printstr("Actual output  : ");
    ft_putnbr(-42);
    printstr("\n\n");

    printstr("Test 3: ft_putnbr(2147483647)\n");
    printstr("Expected output: 2147483647\n");
    printstr("Actual output  : ");
    ft_putnbr(2147483647);
    printstr("\n\n");

    printstr("Test 4: ft_putnbr(-2147483648)\n");
    printstr("Expected output: -2147483648\n");
    printstr("Actual output  : ");
    ft_putnbr(-2147483648);
    printstr("\n\n");
}
#endif

#ifdef EX08
void test_ex08() {
    print_exercise("08", "ft_print_combn");
    printstr("Test 1: ft_print_combn(1)\n");
    printstr("Expected output: 01, 02, 03, 04, 05, 06, 07, 08, 09, 12, 13, 14, 15, 16, 17, 18, 19, 23, 24, 25, 26, 27, 28, 29, 34, 35, 36, 37, 38, 39, 45, 46, 47, 48, 49, 56, 57, 58, 59, 67, 68, 69, 78, 79, 89\n");
    printstr("Actual output  : ");
    ft_print_combn(2);
    printf("\n");
}
#endif

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("\033[0;31m%s: missing number of exercises parameter\n", argv[0]);
        return 1;
    }

    int max_exercise = atoi(argv[1]);

    if (max_exercise >= 9 || max_exercise < 0) {
        printf("Invalid exercise number.\n");
        return 1;
    }

    for (int i = 0; i <= max_exercise && i <= 8; i++) {
        switch (i) {
            case 0:
                #ifdef EX00
                test_ex00();
                #endif
                break;
            case 1:
                #ifdef EX01
                test_ex01();
                #endif
                break;
            case 2:
                #ifdef EX02
                test_ex02();
                #endif
                break;
            case 3:
                #ifdef EX03
                test_ex03();
                #endif
                break;
            case 4:
                #ifdef EX04
                test_ex04();
                #endif
                break;
            case 5:
                #ifdef EX05
                test_ex05();
                #endif
                break;
            case 6:
                #ifdef EX06
                test_ex06();
                #endif
                break;
            case 7:
                #ifdef EX07
                test_ex07();
                #endif
                break;
            case 8:
                #ifdef EX08
                test_ex08();
                #endif
                break;
        }
    }
    return 0;
}

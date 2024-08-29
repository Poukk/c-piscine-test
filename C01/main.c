#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

void compare_output(const char* test_name, const char* expected, const char* actual) {
    printf("%s\n", test_name);
    printf("Expected output: %s\n", expected);
    printf("Actual output  : %s\n", actual);
    printf("Diff: %s%s%s\n\n", strcmp(expected, actual) == 0 ? GREEN : RED, 
           strcmp(expected, actual) == 0 ? "OK" : "KO", RESET);
}

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

#ifdef EX00
void ft_ft(int *nbr);
#endif

#ifdef EX01
void ft_ultimate_ft(int *********nbr);
#endif

#ifdef EX02
void ft_swap(int *a, int *b);
#endif

#ifdef EX03
void ft_div_mod(int a, int b, int *div, int *mod);
#endif

#ifdef EX04
void ft_ultimate_div_mod(int *a, int *b);
#endif

#ifdef EX05
void ft_putstr(char *str);
#endif

#ifdef EX06
int ft_strlen(char *str);
#endif

#ifdef EX07
void ft_rev_int_tab(int *tab, int size);
#endif

#ifdef EX08
void ft_sort_int_tab(int *tab, int size);
#endif

#ifdef EX00
void test_ex00() {
    print_exercise("00", "ft_ft");
    int n = 0;
    ft_ft(&n);
    char expected[20], actual[20];
    snprintf(expected, sizeof(expected), "%d", 42);
    snprintf(actual, sizeof(actual), "%d", n);
    compare_output("Test 1: ft_ft(&n)", expected, actual);
}
#endif

#ifdef EX01
void test_ex01() {
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
#endif

#ifdef EX02
void test_ex02() {
    print_exercise("02", "ft_swap");
    int a = 42, b = 24;
    ft_swap(&a, &b);
    char expected[40], actual[40];
    snprintf(expected, sizeof(expected), "a = %d, b = %d", 24, 42);
    snprintf(actual, sizeof(actual), "a = %d, b = %d", a, b);
    compare_output("Test 1: ft_swap(&a, &b)", expected, actual);
}
#endif

#ifdef EX03
void test_ex03() {
    print_exercise("03", "ft_div_mod");
    int a = 42, b = 10, div = 0, mod = 0;
    ft_div_mod(a, b, &div, &mod);
    char expected[40], actual[40];
    snprintf(expected, sizeof(expected), "div = %d, mod = %d", 4, 2);
    snprintf(actual, sizeof(actual), "div = %d, mod = %d", div, mod);
    compare_output("Test 1: ft_div_mod(42, 10, &div, &mod)", expected, actual);
}
#endif

#ifdef EX04
void test_ex04() {
    print_exercise("04", "ft_ultimate_div_mod");
    int a = 42, b = 10;
    ft_ultimate_div_mod(&a, &b);
    char expected[40], actual[40];
    snprintf(expected, sizeof(expected), "a = %d, b = %d", 4, 2);
    snprintf(actual, sizeof(actual), "a = %d, b = %d", a, b);
    compare_output("Test 1: ft_ultimate_div_mod(&a, &b)", expected, actual);
}
#endif

#ifdef EX05
void test_ex05() {
    print_exercise("05", "ft_putstr");
    char str[] = "Hello, World!";
    write(1, "Test 1: ft_putstr(\"Hello, World!\")\n", 36);
    write(1, "Expected output: Hello, World!\n", 31);
    write(1, "Actual output  : ", 17);
    ft_putstr(str);
    write(1, "\n\n", 2);
}
#endif

#ifdef EX06
void test_ex06() {
    print_exercise("06", "ft_strlen");
    char str[] = "Hello, World!";
    int len = ft_strlen(str);
    char expected[20], actual[20];
    snprintf(expected, sizeof(expected), "%d", 13);
    snprintf(actual, sizeof(actual), "%d", len);
    compare_output("Test 1: ft_strlen(\"Hello, World!\")", expected, actual);
}
#endif

#ifdef EX07
void test_ex07() {
    print_exercise("07", "ft_rev_int_tab");
    int tab[] = {1, 2, 3, 4, 5};
    int size = 5;
    ft_rev_int_tab(tab, size);
    char expected[40], actual[40];
    snprintf(expected, sizeof(expected), "5 4 3 2 1");
    snprintf(actual, sizeof(actual), "%d %d %d %d %d", tab[0], tab[1], tab[2], tab[3], tab[4]);
    compare_output("Test 1: ft_rev_int_tab({1, 2, 3, 4, 5}, 5)", expected, actual);
}
#endif

#ifdef EX08
void test_ex08() {
    print_exercise("08", "ft_sort_int_tab");
    int tab[] = {5, 2, 8, 1, 9};
    int size = 5;
    ft_sort_int_tab(tab, size);
    char expected[40], actual[40];
    snprintf(expected, sizeof(expected), "1 2 5 8 9");
    snprintf(actual, sizeof(actual), "%d %d %d %d %d", tab[0], tab[1], tab[2], tab[3], tab[4]);
    compare_output("Test 1: ft_sort_int_tab({5, 2, 8, 1, 9}, 5)", expected, actual);
}
#endif

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("\033[0;31m%s: missing number of exercises parameter\n", argv[0]);
        return 1;
    }

    int max_exercise = atoi(argv[1]);

    if (max_exercise > 8 || max_exercise < 0) {
        printf("%sC01 Test: Invalid exercise number.\n", RED);
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

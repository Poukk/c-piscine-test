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
char *ft_strcpy(char *dest, char *src);
#endif

#ifdef EX01
char *ft_strncpy(char *dest, char *src, unsigned int n);
#endif

#ifdef EX02
int ft_str_is_alpha(char *str);
#endif

#ifdef EX03
int ft_str_is_numeric(char *str);
#endif

#ifdef EX04
int ft_str_is_lowercase(char *str);
#endif

#ifdef EX05
int ft_str_is_uppercase(char *str);
#endif

#ifdef EX06
int ft_str_is_printable(char *str);
#endif

#ifdef EX07
char *ft_strupcase(char *str);
#endif

#ifdef EX08
char *ft_strlowcase(char *str);
#endif

#ifdef EX09
char *ft_strcapitalize(char *str);
#endif

#ifdef EX10
unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);
#endif

#ifdef EX11
void ft_putstr_non_printable(char *str);
#endif

#ifdef EX12
void *ft_print_memory(void *addr, unsigned int size);
#endif

#ifdef EX00
void test_ex00() {
    print_exercise("00", "ft_strcpy");
    char src[] = "Hello, World!";
    char dest[20];
    ft_strcpy(dest, src);
    compare_output("Test 1: ft_strcpy(dest, \"Hello, World!\")", src, dest);
}
#endif

#ifdef EX01
void test_ex01() {
    print_exercise("01", "ft_strncpy");
    char src[] = "Hello, World!";
    char dest[20] = {0};
    ft_strncpy(dest, src, 5);
    compare_output("Test 1: ft_strncpy(dest, \"Hello, World!\", 5)", "Hello", dest);
}
#endif

#ifdef EX02
void test_ex02() {
    print_exercise("02", "ft_str_is_alpha");
    char expected[20], actual[20];
    snprintf(expected, sizeof(expected), "%d", 1);
    snprintf(actual, sizeof(actual), "%d", ft_str_is_alpha("HelloWorld"));
    compare_output("Test 1: ft_str_is_alpha(\"HelloWorld\")", expected, actual);
    
    snprintf(expected, sizeof(expected), "%d", 0);
    snprintf(actual, sizeof(actual), "%d", ft_str_is_alpha("Hello, World!"));
    compare_output("Test 2: ft_str_is_alpha(\"Hello, World!\")", expected, actual);
}
#endif

#ifdef EX03
void test_ex03() {
    print_exercise("03", "ft_str_is_numeric");
    char expected[20], actual[20];
    snprintf(expected, sizeof(expected), "%d", 1);
    snprintf(actual, sizeof(actual), "%d", ft_str_is_numeric("12345"));
    compare_output("Test 1: ft_str_is_numeric(\"12345\")", expected, actual);
    
    snprintf(expected, sizeof(expected), "%d", 0);
    snprintf(actual, sizeof(actual), "%d", ft_str_is_numeric("123abc"));
    compare_output("Test 2: ft_str_is_numeric(\"123abc\")", expected, actual);
}
#endif

#ifdef EX04
void test_ex04() {
    print_exercise("04", "ft_str_is_lowercase");
    char expected[20], actual[20];
    snprintf(expected, sizeof(expected), "%d", 1);
    snprintf(actual, sizeof(actual), "%d", ft_str_is_lowercase("hello"));
    compare_output("Test 1: ft_str_is_lowercase(\"hello\")", expected, actual);
    
    snprintf(expected, sizeof(expected), "%d", 0);
    snprintf(actual, sizeof(actual), "%d", ft_str_is_lowercase("Hello"));
    compare_output("Test 2: ft_str_is_lowercase(\"Hello\")", expected, actual);
}
#endif

#ifdef EX05
void test_ex05() {
    print_exercise("05", "ft_str_is_uppercase");
    char expected[20], actual[20];
    snprintf(expected, sizeof(expected), "%d", 1);
    snprintf(actual, sizeof(actual), "%d", ft_str_is_uppercase("HELLO"));
    compare_output("Test 1: ft_str_is_uppercase(\"HELLO\")", expected, actual);
    
    snprintf(expected, sizeof(expected), "%d", 0);
    snprintf(actual, sizeof(actual), "%d", ft_str_is_uppercase("HELLo"));
    compare_output("Test 2: ft_str_is_uppercase(\"HELLo\")", expected, actual);
}
#endif

#ifdef EX06
void test_ex06() {
    print_exercise("06", "ft_str_is_printable");
    char expected[20], actual[20];
    snprintf(expected, sizeof(expected), "%d", 1);
    snprintf(actual, sizeof(actual), "%d", ft_str_is_printable("Hello, World!"));
    compare_output("Test 1: ft_str_is_printable(\"Hello, World!\")", expected, actual);
    
    char str_with_non_printable[] = "Hello\nWorld";
    snprintf(expected, sizeof(expected), "%d", 0);
    snprintf(actual, sizeof(actual), "%d", ft_str_is_printable(str_with_non_printable));
    compare_output("Test 2: ft_str_is_printable(\"Hello\\nWorld\")", expected, actual);
}
#endif

#ifdef EX07
void test_ex07() {
    print_exercise("07", "ft_strupcase");
    char str[] = "Hello, World!";
    ft_strupcase(str);
    compare_output("Test 1: ft_strupcase(\"Hello, World!\")", "HELLO, WORLD!", str);
}
#endif

#ifdef EX08
void test_ex08() {
    print_exercise("08", "ft_strlowcase");
    char str[] = "Hello, World!";
    ft_strlowcase(str);
    compare_output("Test 1: ft_strlowcase(\"Hello, World!\")", "hello, world!", str);
}
#endif

#ifdef EX09
void test_ex09() {
    print_exercise("09", "ft_strcapitalize");
    char str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
    ft_strcapitalize(str);
    compare_output("Test 1: ft_strcapitalize(\"salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un\")", "Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un", str);
}
#endif

#ifdef EX10
void test_ex10() {
    print_exercise("10", "ft_strlcpy");
    char src[] = "Hello, World!";
    char dest[20];
    unsigned int size = ft_strlcpy(dest, src, sizeof(dest));
    char expected[40], actual[40];
    snprintf(expected, sizeof(expected), "dest: \"Hello, World!\", size: 13");
    snprintf(actual, sizeof(actual), "dest: \"%s\", size: %u", dest, size);
    compare_output("Test 1: ft_strlcpy()", expected, actual);
}
#endif

#ifdef EX11
void test_ex11() {
    print_exercise("11", "ft_putstr_non_printable");
    char str[] = "Coucou\ntu vas bien ?";
    write(1, "Test 1: ft_putstr_non_printable(\"Coucou\\ntu vas bien ?\")\n", 57);
    write(1, "Expected output: Coucou\\0atu vas bien ?\n", 40);
    write(1, "Actual output  : ", 17);
    ft_putstr_non_printable(str);
    write(1, "\n\n", 2);
}
#endif

#ifdef EX12
void test_ex12() {
    print_exercise("12", "ft_print_memory");
    char str[] = "Bonjour les aminches\t\n\tc  est fou\ttout\tce qu on peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n ";
    write(1, "Test 1: ft_print_memory(str, sizeof(str))\n", 42);
    write(1, "Expected output: (see subject for exact format)\n", 48);
    write(1, "Actual output  :\n", 17);
    ft_print_memory(str, sizeof(str));
    write(1, "\n", 1);
}
#endif

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("\033[0;31m%s: missing number of exercises parameter\n", argv[0]);
        return 1;
    }
    
    int max_exercise = atoi(argv[1]);

    if (max_exercise > 12 || max_exercise < 0) {
        printf("%sC02 Test: Invalid exercise number.\n", RED);
        return 1;
    }

    for (int i = 0; i <= max_exercise && i <= 12; i++) {
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
            case 9:
                #ifdef EX09
                test_ex09();
                #endif
                break;
            case 10:
                #ifdef EX10
                test_ex10();
                #endif
                break;
            case 11:
                #ifdef EX11
                test_ex11();
                #endif
                break;
            case 12:
                #ifdef EX12
                test_ex12();
                #endif
                break;
        }
    }
    return 0;
}

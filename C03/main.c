#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

void compare_output(const char* test_name, const char* expected, const char* actual) {
    printf("%s\n", test_name);
    printf("Expected output: %s\n", expected);
    printf("Actual output: %s\n", actual);
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

size_t strlcat(char *dst, const char *src, size_t size) {
    size_t dlen = strlen(dst);
    size_t slen = strlen(src);
    size_t total_len = dlen + slen;

    if (size <= dlen) {
        return slen + size;
    }

    size_t copy_len = size - dlen - 1;
    if (copy_len > slen) {
        copy_len = slen;
    }

    memcpy(dst + dlen, src, copy_len);
    dst[dlen + copy_len] = '\0';

    return total_len;
}

#ifdef EX00
int ft_strcmp(char *s1, char *s2);
#endif

#ifdef EX01
int ft_strncmp(char *s1, char *s2, unsigned int n);
#endif

#ifdef EX02
char *ft_strcat(char *dest, char *src);
#endif

#ifdef EX03
char *ft_strncat(char *dest, char *src, unsigned int nb);
#endif

#ifdef EX04
char *ft_strstr(char *str, char *to_find);
#endif

#ifdef EX05
unsigned int ft_strlcat(char *dest, char *src, unsigned int size);
#endif

#ifdef EX00
void test_ex00() {
    print_exercise("00", "ft_strcmp");
    char s1[] = "Hello";
    char s2[] = "Hello";
    char s3[] = "World";
    char s4[] = "";
    char s5[] = "HelLo";

    char expected[20], actual[20];

    snprintf(expected, sizeof(expected), "%d", strcmp(s1, s2));
    snprintf(actual, sizeof(actual), "%d", ft_strcmp(s1, s2));
    compare_output("Test 1: ft_strcmp(\"Hello\", \"Hello\")", expected, actual);

    snprintf(expected, sizeof(expected), "%d", strcmp(s1, s3));
    snprintf(actual, sizeof(actual), "%d", ft_strcmp(s1, s3));
    compare_output("Test 2: ft_strcmp(\"Hello\", \"World\")", expected, actual);

    snprintf(expected, sizeof(expected), "%d", strcmp(s1, s4));
    snprintf(actual, sizeof(actual), "%d", ft_strcmp(s1, s4));
    compare_output("Test 3: ft_strcmp(\"Hello\", \"\")", expected, actual);

    snprintf(expected, sizeof(expected), "%d", strcmp(s1, s5));
    snprintf(actual, sizeof(actual), "%d", ft_strcmp(s1, s5));
    compare_output("Test 4: ft_strcmp(\"Hello\", \"HelLo\")", expected, actual);
}
#endif

#ifdef EX01
void test_ex01() {
    print_exercise("01", "ft_strncmp");
    char s1[] = "Hello";
    char s2[] = "Hello World";
    char s3[] = "Hell";

    char expected[20], actual[20];

    snprintf(expected, sizeof(expected), "%d", strncmp(s1, s2, 3));
    snprintf(actual, sizeof(actual), "%d", ft_strncmp(s1, s2, 3));
    compare_output("Test 1: ft_strncmp(\"Hello\", \"Hello World\", 3)", expected, actual);

    snprintf(expected, sizeof(expected), "%d", strncmp(s1, s3, 5));
    snprintf(actual, sizeof(actual), "%d", ft_strncmp(s1, s3, 5));
    compare_output("Test 2: ft_strncmp(\"Hello\", \"Hell\", 5)", expected, actual);
}
#endif

#ifdef EX02
void test_ex02() {
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
#endif

#ifdef EX03
void test_ex03() {
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
#endif

#ifdef EX04
void test_ex04() {
    print_exercise("04", "ft_strstr");
    char str[] = "Hello World";
    char to_find[] = "World";
    char to_find_empty[] = "";
    char to_find_not_found[] = "Planet";

    compare_output("Test 1: ft_strstr(\"Hello World\", \"World\")", 
                   strstr(str, to_find) ? strstr(str, to_find) : "NULL",
                   ft_strstr(str, to_find) ? ft_strstr(str, to_find) : "NULL");

    compare_output("Test 2: ft_strstr(\"Hello World\", \"\")", 
                   strstr(str, to_find_empty) ? strstr(str, to_find_empty) : "NULL",
                   ft_strstr(str, to_find_empty) ? ft_strstr(str, to_find_empty) : "NULL");

    compare_output("Test 3: ft_strstr(\"Hello World\", \"Planet\")", 
                   strstr(str, to_find_not_found) ? strstr(str, to_find_not_found) : "NULL",
                   ft_strstr(str, to_find_not_found) ? ft_strstr(str, to_find_not_found) : "NULL");
}
#endif

#ifdef EX05
void test_ex05() {
    print_exercise("05", "ft_strlcat");
    char dest5[20] = "Hello";
    char src5[] = " World";
    char dest5_std[20] = "Hello";
    char dest6[10] = "Hello";
    char src6[] = " World";
    char dest6_std[10] = "Hello";

    char expected[40], actual[40];

    size_t res_std = strlcat(dest5_std, src5, 20);
    size_t res_ft = ft_strlcat(dest5, src5, 20);
    snprintf(expected, sizeof(expected), "%zu - %s", res_std, dest5_std);
    snprintf(actual, sizeof(actual), "%lu - %s", res_ft, dest5);
    compare_output("Test 1: ft_strlcat(\"Hello\", \" World\", 20)", expected, actual);

    res_std = strlcat(dest6_std, src6, 10);
    res_ft = ft_strlcat(dest6, src6, 10);
    snprintf(expected, sizeof(expected), "%zu - %s", res_std, dest6_std);
    snprintf(actual, sizeof(actual), "%lu - %s", res_ft, dest6);
    compare_output("Test 2: ft_strlcat(\"Hello\", \" World\", 10)", expected, actual);
}
#endif

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("\033[0;31m%s: missing number of exercises parameter\n", argv[0]);
        return 1;
    }

    int max_exercise = atoi(argv[1]);

    if (max_exercise > 5 || max_exercise < 0) {
        printf("%sInvalid exercise number.\n", RED);
        return 1;
    }

    for (int i = 0; i <= max_exercise && i <= 5; i++) {
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
        }
    }
    return 0;
}

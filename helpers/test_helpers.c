#include "test_helpers.h"

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

void compare_output(const char* test_name, const char* expected, const char* actual) {
    printf("%s\n", test_name);
    printf("Expected output: %s\n", expected);
    printf("Actual output  : %s\n", actual);
    printf("Diff: %s%s%s\n\n", strcmp(expected, actual) == 0 ? GREEN : RED, 
           strcmp(expected, actual) == 0 ? "OK" : "KO", RESET);
}

void printstr(char *str) {
    while(*str) {
      write(1, str, 1);
      str++;
    }
}
#ifndef TEST_HELPERS_H
#define TEST_HELPERS_H
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

#include <stdio.h>
#include <unistd.h>
#include <string.h>

void print_exercise(char *exercise, char *function);
void printstr(char *str);
void compare_output(const char* test_name, const char* expected, const char* actual);

#endif

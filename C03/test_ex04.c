#include "test_helpers.h"

char *ft_strstr(char *str, char *to_find);

void cpt_test_exercise() {
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

int main() {
    cpt_test_exercise();
    return 0;
}
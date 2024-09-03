#include "test_helpers.h"

char *ft_strcapitalize(char *str);

void cpt_test_exercise() {
    print_exercise("09", "ft_strcapitalize");
    char str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
    ft_strcapitalize(str);
    compare_output("Test 1: ft_strcapitalize(\"salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un\")", "Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un", str);
}

int main() {
    cpt_test_exercise();
    return 0;
}
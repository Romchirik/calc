#include <stdio.h>
#include <string.h>
#include "additional_functions.h"

#define INPUT_STRING_MAXLEN 1000
#define SIGNIFICANT_DIGITS 10

char input_string[INPUT_STRING_MAXLEN + 1];
char postfix_view[2 * INPUT_STRING_MAXLEN + 1];
char pre_input[INPUT_STRING_MAXLEN + 1];

int main() {

    memset(input_string, 0, INPUT_STRING_MAXLEN + 1);
    memset(postfix_view, 0, 2 * INPUT_STRING_MAXLEN + 1);
    gets(pre_input);
    int input_length = 0;
    for (int i = 0; (i < INPUT_STRING_MAXLEN) && (pre_input[i] != '\0'); i++) {
        if (pre_input[i] != ' ') {
            input_string[input_length] = pre_input[i];
            input_length++;
        }
    }
    input_string[input_length] = '\0';
    if (input_length == 0) {
        return 0;
    }
    input_length++;

    convert_to_postfix_view(postfix_view, input_string, input_length);
    printf("%.10f\n", calculate_result(postfix_view));
    return 0;
}

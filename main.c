#include <stdio.h>
#include <string.h>
#include "additional_functions.h"

#define INPUT_STRING_MAXLEN 1000

char input_string[INPUT_STRING_MAXLEN + 1];
char postfix_view[2 * INPUT_STRING_MAXLEN + 1];

int main(int num_args, char **args) {
    if (num_args == 1) {
        return 0;
    }

    memset(input_string, 0, INPUT_STRING_MAXLEN + 1);
    memset(postfix_view, 0, 2 * INPUT_STRING_MAXLEN + 1);

    //make from many arguments one string without spaces
    int input_length = normalize_input(input_string, num_args, args);

    convert_to_postfix_view(postfix_view, input_string, input_length);
    printf("%d\n", calculate_result(postfix_view));
    return 0;
}

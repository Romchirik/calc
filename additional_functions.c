#include <stdlib.h>
#include <string.h>
#include "stack_stuff.h"
#include <stdio.h>

int normalize_input(char *result, int num_args, char **args) {
    int lenght = 0;

    for (int i = 1; i < num_args; i++) {
        strcpy(result + lenght, args[i]);
        lenght += strlen(args[i]);
    }

    return lenght;
}

int convert_to_postfix_view(char *result, char *target, int target_length) {
    int result_length = 0;
    Stack_s *Stack = stack_initialize();

    for (int i = 0; (i < target_length) && (target[i] != '\0'); i++) {

        switch (target[i]) {
            case '(':
                push('(', Stack);
                break;
            case ')':
                while (1) {
                    char tmp = pop(Stack);
                    if (tmp == '(') break;
                    else {
                        result[result_length + 1] = ' ';
                        result[result_length] = tmp;
                        result_length += 2;
                    }
                }
                break;
            case '+':
                while (1) {
                    int tmp = get_top(Stack);
                    if (((tmp == '-') || (tmp == '+') || (tmp == '*') || (tmp == '/')) && (!is_empty(Stack))) {
                        result[result_length + 1] = ' ';
                        result[result_length] = pop(Stack);
                        result_length += 2;
                    } else {
                        push('+', Stack);
                        break;
                    }
                }
                break;
            case '-':
                if (i == 0) {
                    printf("Invalid input (use unary - with '(' and ')'");
                    clear_stack(Stack);
                    free(Stack);
                    exit(0);
                } else if (target[i - 1] == '(') {
                    push('?', Stack);
                    break;
                }
                while (1) {
                    int tmp = get_top(Stack);
                    if (((tmp == '-') || (tmp == '+') || (tmp == '*') || (tmp == '/') || (tmp == '?')) &&
                        (!is_empty(Stack))) {
                        result[result_length + 1] = ' ';
                        result[result_length] = pop(Stack);
                        result_length += 2;
                    } else {
                        push('-', Stack);
                        break;
                    }
                }
                break;
            case '*':
                while (1) {
                    int tmp = get_top(Stack);
                    if (((tmp == '*') || (tmp == '/') || (tmp == '?')) && (!is_empty(Stack))) {
                        result[result_length + 1] = ' ';
                        result[result_length] = pop(Stack);
                        result_length += 2;
                    } else {
                        push('*', Stack);
                        break;
                    }
                }
                break;
            case '/':
                while (1) {
                    int tmp = get_top(Stack);
                    if (((tmp == '*') || (tmp == '/') || (tmp == '?')) && (!is_empty(Stack))) {
                        result[result_length + 1] = ' ';
                        result[result_length] = pop(Stack);
                        result_length += 2;
                    } else {
                        push('/', Stack);
                        break;
                    }
                }
                break;
            default:
                while ((47 < target[i]) && (target[i] < 57)) {
                    result[result_length] = target[i];
                    result_length++;
                    i++;
                }
                result[result_length] = ' ';
                result_length++;
                i--;
                break;
        }

    }
    while (!is_empty(Stack)) {
        result[result_length + 1] = ' ';
        result[result_length] = pop(Stack);
        result_length += 2;
    }
    clear_stack(Stack);
    free(Stack);
    return result_length;
}

int calculate_result(char *postfix_view) {
    Stack_s *Stack = stack_initialize();

    int operand1, operand2;
    for (int i = 0; (i < 2000) && (postfix_view[i] != '\0'); i++) {
        switch (postfix_view[i]) {
            case '+':
                operand2 = pop(Stack);
                operand1 = pop(Stack);
                push(operand1 + operand2, Stack);
                break;
            case '-':
                operand2 = pop(Stack);
                operand1 = pop(Stack);
                push(operand1 - operand2, Stack);
                break;
            case '*':
                operand2 = pop(Stack);
                operand1 = pop(Stack);
                push(operand1 * operand2, Stack);
                break;
            case '/':
                operand2 = pop(Stack);
                operand1 = pop(Stack);
                if (operand2 == 0) {
                    printf("Division by zero, terminating...\n");
                    clear_stack(Stack);
                    free(Stack);
                    exit(0);
                }
                push(operand1 / operand2, Stack);
                break;
            case '?':
                operand1 = pop(Stack);
                push(0 - operand1, Stack);
                break;
            case ' ':
                continue;
            default: {
                short int number_len = 0;
                int tmp_number = 0;
                int power = 1;
                char number_to_translate[15];

                number_to_translate[number_len] = postfix_view[i];
                number_len++;
                i++;

                while ((postfix_view[i] != ' ') && (postfix_view[i] != '\0')) {
                    number_to_translate[number_len] = postfix_view[i];
                    i++;
                    number_len++;
                }

                for (int j = number_len - 1; j >= 0; j--) {
                    tmp_number += (number_to_translate[j] - 48) * power;
                    power *= 10;
                }

                push(tmp_number, Stack);
                memset(number_to_translate, 0, 15);
            }
        }
    }
    int r = pop(Stack);
    clear_stack(Stack);
    free(Stack);
    return r;
}

#include "additional_functions.h"

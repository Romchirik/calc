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
                    if (((tmp == '-') || (tmp == '+') || (tmp == '*') || (tmp == '/') || (tmp == '?')) &&
                        (!is_empty(Stack))) {
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
                    push('?', Stack);
                    break;
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
            case ' ':
                continue;
            default:
                while (('0' <= target[i]) && (target[i] <= '9')) {
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

double calculate_result(char *postfix_view) {
    Stack_sf *Stack = stack_initialize_f();

    long double operand1, operand2;
    for (int i = 0; (i < 500010) && (postfix_view[i] != '\0'); i++) {
        switch (postfix_view[i]) {
            case '+':
                operand2 = pop_f(Stack);
                operand1 = pop_f(Stack);
                push_f(operand1 + operand2, Stack);
                break;
            case '-':
                operand2 = pop_f(Stack);
                operand1 = pop_f(Stack);
                push_f(operand1 - operand2, Stack);
                break;
            case '*':
                operand2 = pop_f(Stack);
                operand1 = pop_f(Stack);
                push_f(operand1 * operand2, Stack);
                break;
            case '/':
                operand2 = pop_f(Stack);
                operand1 = pop_f(Stack);
                if (operand2 == 0) {
                    printf("Division by zero, terminating...\n");
                    clear_stack_f(Stack);
                    free(Stack);
                    exit(0);
                }
                push_f(operand1 / operand2, Stack);
                break;
            case '?':
                operand1 = pop_f(Stack);
                push_f((-operand1), Stack);
                break;
            case ' ':
                continue;
            default: {
                char number[20] = {0};
                char digits_counter = 0;
                int tmp_number = 0;

                while ('0' <= (postfix_view[i]) && (postfix_view[i] <= '9')) {
                    number[digits_counter] = postfix_view[i];
                    digits_counter++;
                    i++;
                }
                tmp_number = atoi(number);
                push_f(tmp_number, Stack);

            }
        }
    }
    long double r = pop_f(Stack);
    clear_stack_f(Stack);
    free(Stack);
    return r;
}

#include "additional_functions.h"

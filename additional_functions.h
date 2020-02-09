#ifndef CALC_ADDITIONAL_FUNCTIONS_H
#define CALC_ADDITIONAL_FUNCTIONS_H

int normalize_input(char *result, int num_args, char **args);

int convert_to_postfix_view(char *result, char *target, int target_length);

int calculate_result(char *postfix_view);

#endif //CALC_ADDITIONAL_FUNCTIONS_H

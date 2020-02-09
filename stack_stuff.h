#ifndef CALC_STACK_STUFF_H
#define CALC_STACK_STUFF_H

struct list;
typedef struct stack Stack_s;

void clear_stack(Stack_s *S);

Stack_s *stack_initialize();

int get_top(Stack_s *S);

int pop(Stack_s *S);

void push(int value, Stack_s *S);

int is_empty(Stack_s *S);

#endif //CALC_STACK_STUFF_H

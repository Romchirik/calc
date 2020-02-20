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

struct list_f;
typedef struct stack_f Stack_sf;

void clear_stack_f(Stack_sf *S);

Stack_sf *stack_initialize_f();

double get_top_f(Stack_sf *S);

double pop_f(Stack_sf *S);

void push_f(double value, Stack_sf *S);

int is_empty_f(Stack_sf *S);

#endif //CALC_STACK_STUFF_H

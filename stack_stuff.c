#include <stdlib.h>

struct list {
    long long int data;
    struct list *next;
};

typedef struct stack {
    struct list *top;
} Stack_s;

void clear_stack(Stack_s *S) {
    struct list *p;
    while (S->top) {
        p = S->top;
        S->top = p->next;
        free(p);
    }
}

Stack_s *stack_initialize() { // returns an empty stack
    Stack_s *S;
    S = (Stack_s *) malloc(sizeof(Stack_s));
    S->top = NULL;
    return S;
}

int get_top(Stack_s *S) { //return top value of stack
    if (S->top)
        return (S->top->data);
    else
        return 0;
}

int pop(Stack_s *S) { //delete top stack value and returns it
    int data;
    struct list *tmp_top;

    tmp_top = S->top;
    data = tmp_top->data;
    S->top = tmp_top->next;
    free(tmp_top);

    return data;
}

void push(int value, Stack_s *S) { //puts value of value (lol) in top of stack S
    struct list *p;
    p = (struct list *) malloc(sizeof(struct list));
    p->data = value;
    p->next = S->top;
    S->top = p;
}

int is_empty(Stack_s *S) { //return 1 if stack is empty, and 0 if there is some date in stack
    return (S->top == NULL);
}

struct list_f {
    long double data;
    struct list_f *next;
};

typedef struct stack_f {
    struct list_f *top;
} Stack_sf;

void clear_stack_f(Stack_sf *S) {
    struct list_f *p;
    while (S->top) {
        p = S->top;
        S->top = p->next;
        free(p);
    }
}

Stack_sf *stack_initialize_f() { // returns an empty stack
    Stack_sf *S;
    S = (Stack_sf *) malloc(sizeof(Stack_sf));
    S->top = NULL;
    return S;
}

long double get_top_f(Stack_sf *S) { //return top value of stack
    if (S->top)
        return (S->top->data);
    else
        return 0;
}

long double pop_f(Stack_sf *S) { //delete top stack value and returns it
    long double data;
    struct list_f *tmp_top;

    tmp_top = S->top;
    data = tmp_top->data;
    S->top = tmp_top->next;
    free(tmp_top);

    return data;
}

void push_f(long double value, Stack_sf *S) { //puts value of value (lol) in top of stack S
    struct list_f *p;
    p = (struct list_f *) malloc(sizeof(struct list_f));
    p->data = value;
    p->next = S->top;
    S->top = p;
}

int is_empty_f(Stack_sf *S) { //return 1 if stack is empty, and 0 if there is some date in stack
    return (S->top == NULL);
}


#include "stack_stuff.h"
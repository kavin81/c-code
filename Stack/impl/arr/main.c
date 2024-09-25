#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int arr[MAX];
    int top;
} Stack;

Stack *init()
{
    Stack *new_stack = (Stack *)malloc(sizeof(Stack));
    new_stack->top = -1;
    return new_stack;
}

void push(int x, Stack *s)
{
    if (s->top == MAX - 1)
    {
        printf("Stack is full\n");
        return;
    }
    s->arr[++s->top] = x;
};

int pop(Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    return s->arr[s->top--];
};

void print(Stack *s)
{
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d -> ", s->arr[i]);
    }
    printf("NULL\n");
};
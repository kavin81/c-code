#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Stack
{
    Node *top;
} Stack;

Stack *init()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

void push(int data, Stack *stack)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack *stack){
    if(stack->top == NULL){
        printf("Stack is empty\n");
        return;
    }

    Node *temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

void printStack(Stack *stack){
    Node *temp = stack->top;
    while(temp != NULL){
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf(" NULL\n");
}

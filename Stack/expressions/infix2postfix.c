#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../impl/arr/main.c"


int isOperand(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    else if (c >= 'a' && c <= 'z')
        return 1;
    else if (c >= 'A' && c <= 'Z')
        return 1;
    else
        return 0;
}

int isOperator(char c)
{
    switch (c)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '$':
        return 1;
    default:
        return 0;
    }
}

int prec(char a, char b)
{
    switch (a)
    {
    case '$':
        return 1;
    case '*':
    case '/':
        if (b == '$')
            return 0;
        else
            return 1;
    case '+':
    case '-':
        if (b == '+' || b == '-'|| b == '#')
            return 1;
        else
            return 0;
    case '#':
        return 0;
    }
}

int main()
{
    // operator stack
    Stack *s = init();

    int i = 0;
    char exp[100], tmp;

    scanf("%s", exp);

    while (exp[i] != '\0')
    {
        if (isOperand(exp[i]))
            printf("%c", exp[i]);
        else if (exp[i] == '(')
            push(s, exp[i]);
        else if (exp[i] == ')')
        {
            while ((tmp = pop(s)) != '(')
                printf("%c", tmp);
        }
        else if (isOperator(exp[i]))
        {
            while (s->top != -1 && prec(s->arr[s->top], exp[i]))
                printf("%c", pop(s));
            push(s, exp[i]);
        }
        i++;
    }
    while (s->top != -1)
        printf("%c", pop(s));

    return 0;
}

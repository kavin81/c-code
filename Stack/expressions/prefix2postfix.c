#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../impl/arr/main.c"

#define MAX 100

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


int main()
{
    char exp[MAX];
    char res[MAX];
    scanf("%s", exp);
    int size = strlen(exp);

    Stack *s = init();

    for(int i = size - 1; i >= 0; i--)
    {
        if(isOperand(exp[i]))
        {
            strcat(res, &exp[i]);
        }
        else if(isOperator(exp[i]))
        {
            char op1 = pop(s);
            char op2 = pop(s);

            char temp[MAX];
            temp[0] = op1;
            temp[1] = op2;
            temp[2] = exp[i];
            temp[3] = '\0';

            strcat(res, temp);
        }
    }
}
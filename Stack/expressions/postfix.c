#include <stdio.h>
#include <stdlib.h>
#include "../impl/arr/main.c"

#define MAX 100

int main()
{
    char exp[MAX];
    int i = 0;
    scanf("%s", exp);

    Stack *s = init();

    while(s != '\0'){
        switch(exp[i]){
            case '+':
                push(pop(s) + pop(s), s);
                break;
            case '-':
                push(pop(s) - pop(s), s);
                break;
            case '*':
                push(pop(s) * pop(s), s);
                break;
            case '/':
                push(pop(s) / pop(s), s);
                break;
            default:
                push(exp[i] - '0', s);
        }
        i++;
    }
    return 0;
}
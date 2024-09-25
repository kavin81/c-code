#include <stdio.h>
#include <stdlib.h>
#include "../impl/arr/main.c"

void toh(int n, Stack *source, Stack *aux, Stack *dest)
{
    if (n == 1)
    {
        push(pop(source), dest);
        return;
    }
    // SDA -> d,s swap of (dsa)
    // ASD  , <ASD> <ASD>
    toh(n - 1, source, dest, aux);
    push(pop(source), dest);
    toh(n - 1, aux, source, dest);
}

int main()
{
    Stack *src = init(),
          *aux = init(),
          *dest = init();

    int n = 3;

    for (int i = n; i > 0; i--)
    {
        push(i, src);
    }
    // display the source stack
    printf("Source: ");
    print(src);
    // call the tower of hanoi function
    toh(n, src, aux, dest);
    // display the destination stack
    printf("Destination: ");
    print(dest);
    return 0;
}
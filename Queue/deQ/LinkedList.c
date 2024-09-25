// circular queue impl

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct queue
{
    int data;
} queue;

struct queue q[MAX];


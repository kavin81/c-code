#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct queue
{
    int items[MAX];
    int front;
    int rear;
} queue;

queue *init()
{
    queue *q = (queue *)malloc(sizeof(queue));

    q->front = q->rear = -1;

    return q;
}

void enqueue(int x, queue *q)
{
    if (q->front == -1 && q -> rear == -1)
    {
        q->front = q->rear = 0;
        q->items[q->rear] = x;
    }
    else if ((q->rear + 1) % MAX == q->front)
    {
        printf("Queue is full\n");
    }
    else
    {
        q->rear = (q->rear + 1) % MAX;
        q->items[q->rear] = x;
    }
}

int dequeue(queue *q)
{
    int x;

    if (q->front == -1)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else if (q->front == q->rear)
    {
        x = q->items[q->front];
        q->front = q->rear = -1;
    }
    else
    {
        x = q->items[q->front];
        q->front = (q->front + 1) % MAX;
    }

    return x;
}

void display(queue *q){
    int i = q->front;

    if(q->front == -1){
        printf("Queue is empty\n");
    }
    else{
        while(i != q->rear){
            printf("%d ->", q->items[i]);
            i = (i + 1) % MAX;
        }
        printf("%d -> NULL\n", q->items[q->rear]);
    }
}

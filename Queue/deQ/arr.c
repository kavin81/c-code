// circular dequeue using array with insert/delete at both ends

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int arr[MAX];
    int front, rear;
} Queue;

Queue *init()
{
    Queue *new_queue = (Queue *)malloc(sizeof(Queue));
    new_queue->front = new_queue->rear = -1;
    return new_queue;
}

void enQ_front(Queue *q, int data)
{
    // if queue is full / like q is liek
    if ((q->front == 0 && q->rear == MAX - 1) || (q->front == q->rear + 1))
    {
        printf("Queue is full\n");
        return;
    }
    // if queue is empty
    if (q->front == -1)
    {
        q->front = q->rear = 0;
    }
    // if front is at 0, then move it to the end
    else if (q->front == 0)
    {
        q->front = MAX - 1;
    }
    else
    {
        // move front to the left
        q->front = q->front - 1;
    }
    q->arr[q->front] = data;
}

void enQ_rear(Queue *q, int data)
{
    if ((q->front == 0 && q->rear == MAX - 1) || (q->front == q->rear + 1))
    {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1)
    {
        q->front = q->rear = 0;
    }
    else if (q->rear == MAX - 1)
    {
        q->rear = 0;
    }
    else
    {
        q->rear = q->rear + 1;
    }
    q->arr[q->rear] = data;
}

int deQ_front(Queue *q)
{
    if (q->front == -1)
    {
        printf("Queue is empty\n");
        return -1;
    }
    int data = q->arr[q->front];
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        if (q->front == MAX - 1)
        {
            q->front = 0;
        }
        else
        {
            q->front = q->front + 1;
        }
    }
    return data;
}

int deQ_rear(Queue *q)
{
    if (q->front == -1)
    {
        printf("Queue is empty\n");
        return -1;
    }
    int data = q->arr[q->rear];
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        if (q->rear == 0)
        {
            q->rear = MAX - 1;
        }
        else
        {
            q->rear = q->rear - 1;
        }
    }
    return data;
}
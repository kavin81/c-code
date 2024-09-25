#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

Queue *createQueue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enQueue(Queue *queue, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

void deQueue(Queue *queue) {
    if (queue->front == NULL) {
        return;
    }
    Node *temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
}

void printQueue(Queue *queue) {
    Node *temp = queue->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue *queue = createQueue();
    enQueue(queue, 10);
    enQueue(queue, 20);
    enQueue(queue, 30);
    enQueue(queue, 40);
    printQueue(queue);
    deQueue(queue);
    printQueue(queue);
    return 0;
}
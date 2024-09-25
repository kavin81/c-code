// priority queue

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node
{
    int items[MAX];
    int front,rear; // first + last element index
} Queue;



Queue *init(){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q -> rear = -1;
    q -> front = -1;
    return q;
}


// insert / enqueueu , remove / dequeue



void qinsert(int x, Queue *q){
    if((q -> rear + 1) %MAX == q-> front){
        printf("queue is full...\n");
        return;
    }

    q -> rear 
};

int qremove(Queue *q){

};
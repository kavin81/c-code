#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// THIS IS ASC ORDER prio queue
// see line 22 for DESC order mode

typedef struct pqueue
{
    int data;
    int pty;
} pqueue;



struct pqueue pq[MAX];
int count = 0;

void enqueue(int data, int pty){
    int i = count - 1;
    // finds the right place to insert

    // change > -> < for DESC/min priority
    while (i >= 0 && pq[i].pty > pty)
    {
        pq[i + 1] = pq[i];
        i--;
    }
    // inserts the data
    pq[i + 1].data = data;
    pq[i + 1].pty = pty;

    // increments the count
    count++;

}

int dequeue(){

    if (count == 0)
    {
        printf("Queue is empty\n");
        return -1;
    }

    int data = pq[count - 1].data;
    count--;
    return data;
}

void display(){
    for (int i = 0; i < count; i++)
    {
        printf("prio: %d | data: %d \n", pq[i].pty, pq[i].data);
    }
    printf("\n");
}
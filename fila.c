//SC 3037347 FELIPE CORSI
//SC 3037649 FABIANO JUNIOR
//SC 3037851 GABRIEL HENRIQUE

#include <stdio.h>
#include <string.h>
#include "fila.h"

void createQueue(t_queue *q) {
    q->front = 0;
    q->back = -1;
    q->size = 0;
}

int isEmpty(t_queue *q) {
    return q->size == 0;
}

int isFull(t_queue *q) {
    return q->size == MAX_QUEUE_SIZE;
}

void enqueue(t_queue *q, Client client) {
    if (!isFull(q)) {
        q->back = (q->back + 1) % MAX_QUEUE_SIZE;
        q->clients[q->back] = client;
        q->size++;
    }
}

Client dequeue(t_queue *q) {
    Client client = {"", ""};
    if (!isEmpty(q)) {
        client = q->clients[q->front];
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
        q->size--;
    }
    return client;
}
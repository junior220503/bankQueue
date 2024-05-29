#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE_SIZE 100

typedef struct {
    char type;
    char name[50];
} Client;

typedef struct {
    Client clients[MAX_QUEUE_SIZE];
    int front;
    int back;
    int size;
} t_queue;

void createQueue(t_queue *q);
int isEmpty(t_queue *q);
int isFull(t_queue *q);
void enqueue(t_queue *q, Client client);
Client dequeue(t_queue *q);

#endif
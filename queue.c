#include <stdio.h>
#include <stdlib.h>

typedef struct queueNode 
{
    void* value;
    struct queueNode* next;
}queueNode;

typedef struct queue
{
    size_t size;
    queueNode* head;
    queueNode* last;
}queue;

void enqueue(void* value, queue* q)
{
    queueNode* newNode = malloc(sizeof(queueNode));
    newNode->value = value;
    if (q->size == 0) 
    {
        q->head = newNode;
        q->last = q->head;
        q->size++;
        return;
    }
    q->last->next = newNode;
    q->last = newNode;
    q->size++;
}

void* dequeue(queue* q)
{
    if (q->size == 0) return "Empty";
    void* tmp = q->head->value;
    queueNode* toGo = q->head;
    q->head = q->head->next;
    free(toGo);
    return tmp;
}

int main(void)
{
    queue* q = malloc(sizeof(queue));
    enqueue("Blitz", q);
    enqueue("Blitz2", q);
    printf("%s\n", (char*)dequeue(q));
    printf("%s\n", (char*)dequeue(q));
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct QueueNode {
    char data;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q, char value) {
    struct QueueNode* newNode = (struct QueueNode*) malloc(sizeof(struct QueueNode));
    newNode->data = value;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

char dequeue(struct Queue* q) {
    if (q->front == NULL) return '\0';
    struct QueueNode* temp = q->front;
    char val = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return val;
}

void printQueue(struct Queue* q) {
    struct QueueNode* temp = q->front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%c -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Queue* q = createQueue();

    enqueue(q, 'A');
    enqueue(q, 'B');
    enqueue(q, 'C');

    char removed = dequeue(q);
    printf("Dequeued value: %c\n", removed);

    printQueue(q);

    return 0;
}

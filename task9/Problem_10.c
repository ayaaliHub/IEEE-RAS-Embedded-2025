#include <stdio.h>
#include <stdlib.h>

struct QueueNode {
    int data;
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

int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

int enqueue(struct Queue* q, int value) {
    struct QueueNode* newNode = (struct QueueNode*) malloc(sizeof(struct QueueNode));
    if (newNode == NULL) return 0;
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return 1;
    }

    q->rear->next = newNode;
    q->rear = newNode;
    return 1;
}

// Dequeue
int dequeue(struct Queue* q) {
    if (isEmpty(q)) return -1;
    struct QueueNode* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return value;
}

// Get front
int getFront(struct Queue* q) {
    if (isEmpty(q)) return -1;
    return q->front->data;
}

// Get rear
int getRear(struct Queue* q) {
    if (isEmpty(q)) return -1;
    return q->rear->data;
}

// Print queue
void printQueue(struct Queue* q) {
    struct QueueNode* temp = q->front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Queue* q = createQueue();

    if (isEmpty(q)) printf("Queue is empty.\n");

    if (enqueue(q, 10)) printf("Enqueued 10\n");
    if (enqueue(q, 20)) printf("Enqueued 20\n");

    printQueue(q);

    printf("Front: %d\n", getFront(q));
    printf("Rear: %d\n", getRear(q));

    dequeue(q);
    printQueue(q);

    printf("Front: %d\n", getFront(q));
    printf("Rear: %d\n", getRear(q));

    return 0;
}

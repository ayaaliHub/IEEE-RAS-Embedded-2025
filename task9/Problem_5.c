#include <stdio.h>
#include <stdlib.h>

struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
};

struct DNode* createDNode(int value) {
    struct DNode* newNode = (struct DNode*) malloc(sizeof(struct DNode));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct DNode* insertAtBeginning(struct DNode* head, int value) {
    struct DNode* newNode = createDNode(value);
    if (head != NULL) {
        newNode->next = head;
        head->prev = newNode;
    }
    return newNode;
}

void printDoublyList(struct DNode* head) {
    struct DNode* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct DNode* head = NULL;

    head = insertAtBeginning(head, 30);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 10);

    printDoublyList(head);

    return 0;
}

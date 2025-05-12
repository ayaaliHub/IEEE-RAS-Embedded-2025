#include <stdio.h>
#include <stdlib.h>

struct CNode {
    int data;
    struct CNode* next;
};

struct CNode* createCNode(int value) {
    struct CNode* newNode = (struct CNode*) malloc(sizeof(struct CNode));
    newNode->data = value;
    newNode->next = newNode;
    return newNode;
}

struct CNode* insertAtPosition(struct CNode* head, int value, int position) {
    struct CNode* newNode = createCNode(value);
    if (head == NULL) {
        return newNode;
    }

    if (position == 0) {
        struct CNode* last = head;
        while (last->next != head) {
            last = last->next;
        }
        newNode->next = head;
        last->next = newNode;
        return newNode;
    }

    struct CNode* temp = head;
    int index = 0;
    while (index < position - 1 && temp->next != head) {
        temp = temp->next;
        index++;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

void printCircularList(struct CNode* head) {
    if (head == NULL) return;
    struct CNode* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

int main() {
    struct CNode* head = NULL;

    head = createCNode(10);
    head = insertAtPosition(head, 20, 1);
    head = insertAtPosition(head, 30, 2);
    head = insertAtPosition(head, 5, 0);

    printCircularList(head);

    return 0;
}

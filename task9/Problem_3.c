#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    int length = 0;
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
        length++;
    }
    printf("NULL\n");
    printf("Length: %d\n", length);
}

struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

int getNodeValue(struct Node* head, int position) {
    int index = 0;
    struct Node* current = head;
    while (current != NULL) {
        if (index == position) {
            return current->data;
        }
        current = current->next;
        index++;
    }
    return -1;
}

struct Node* insertAtPosition(struct Node* head, int position, int value) {
    struct Node* newNode = createNode(value);
    if (position == 0) {
        newNode->next = head;
        return newNode;
    }
    int index = 0;
    struct Node* current = head;
    while (current != NULL && index < position - 1) {
        current = current->next;
        index++;
    }
    if (current == NULL) {
        return head;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

int main() {
    struct Node* head = NULL;

    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);

    printList(head);

    int pos = 2;
    int valueAtPos = getNodeValue(head, pos);
    printf("Value at position %d: %d\n", pos, valueAtPos);

    head = insertAtPosition(head, 2, 99);

    printList(head);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct StackNode {
    int data;
    struct StackNode* next;
};

struct StackNode* push(struct StackNode* top, int value) {
    struct StackNode* newNode = (struct StackNode*) malloc(sizeof(struct StackNode));
    newNode->data = value;
    newNode->next = top;
    return newNode;
}

void printStack(struct StackNode* top) {
    struct StackNode* temp = top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void swapTopTwo(struct StackNode* top) {
    if (top == NULL || top->next == NULL) return;
    int temp = top->data;
    top->data = top->next->data;
    top->next->data = temp;
}

int main() {
    struct StackNode* top = NULL;

    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);

    printf("Before swap:\n");
    printStack(top);

    swapTopTwo(top);

    printf("After swap:\n");
    printStack(top);

    return 0;
}

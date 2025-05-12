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

struct StackNode* pop(struct StackNode* top, int* poppedValue) {
    if (top == NULL) return NULL;
    *poppedValue = top->data;
    struct StackNode* temp = top;
    top = top->next;
    free(temp);
    return top;
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

int main() {
    struct StackNode* top = NULL;
    int popped;

    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);

    top = pop(top, &popped);
    printf("Popped value: %d\n", popped);

    printStack(top);

    return 0;
}

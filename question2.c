#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int isEmpty(struct Node* top) {
    return top == NULL;
}

void push(struct Node** top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top; 
    *top = newNode;        
    printf("%d pushed to stack\n", data);
}

int pop(struct Node** top) {
    if (isEmpty(*top)) {
        printf("Stack underflow\n");
        return -1;
    }
    struct Node* temp = *top;
    *top = (*top)->next;  
    int poppedValue = temp->data;
free(temp);
    return poppedValue;
}

int peek(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

int main() {
    struct Node* stack = NULL;

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("%d popped from stack\n", pop(&stack));
    printf("Top element is %d\n", peek(stack));

    return 0;
}
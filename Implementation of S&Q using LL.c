#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/* -------------------- STACK OPERATIONS -------------------- */

// PUSH = insert at beginning
void push(struct Node **top, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *top;
    *top = newNode;
}

// POP = delete from beginning
void pop(struct Node **top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    struct Node* temp = *top;
    printf("Popped: %d\n", temp->data);
    *top = (*top)->next;
    free(temp);
}

// Display stack
void displayStack(struct Node *top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct Node *temp = top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* -------------------- QUEUE OPERATIONS -------------------- */

// ENQUEUE = insert at end
void enqueue(struct Node **front, struct Node **rear, int value) {
    struct Node* newNode = createNode(value);

    if (*rear == NULL) {
        *front = *rear = newNode;
        return;
    }
    (*rear)->next = newNode;
    *rear = newNode;
}

// DEQUEUE = delete from front
void dequeue(struct Node **front, struct Node **rear) {
    if (*front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    struct Node* temp = *front;
    printf("Dequeued: %d\n", temp->data);
    *front = (*front)->next;

    if (*front == NULL)
        *rear = NULL;

    free(temp);
}

// Display queue
void displayQueue(struct Node *front) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* -------------------- MAIN FUNCTION -------------------- */

int main() {
    struct Node *stackTop = NULL;
    struct Node *queueFront = NULL, *queueRear = NULL;

    int choice, value;

    while (1) {
        printf("\nMENU:\n");
        printf("1. PUSH (Stack)\n");
        printf("2. POP (Stack)\n");
        printf("3. Display Stack\n");
        printf("4. ENQUEUE (Queue)\n");
        printf("5. DEQUEUE (Queue)\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(&stackTop, value);
                break;
            case 2:
                pop(&stackTop);
                break;
            case 3:
                displayStack(stackTop);
                break;
            case 4:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(&queueFront, &queueRear, value);
                break;
            case 5:
                dequeue(&queueFront, &queueRear);
                break;
            case 6:
                displayQueue(queueFront);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}




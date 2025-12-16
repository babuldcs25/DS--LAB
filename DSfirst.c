#include <stdio.h>
#include <stdlib.h>

#define max 5
int stack[max];
int top = -1;

void push() {
    int item;
    if (top == max - 1) {
        printf("\nStack overflow\n");
    } else {
        printf("Enter the element to push: ");
        scanf("%d", &item);
        top++;
        stack[top] = item;
        printf("Element %d pushed into stack\n", item);
    }
}

void pop() {
    if (top == -1) {
        printf("\nStack underflow\n");
    } else {
        printf("Element %d popped out of the stack\n", stack[top]);
        top--;
    }
}

void display() {
    if (top == -1) {
        printf("\nStack is empty\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

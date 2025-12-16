#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue() {
    int item;
    if (rear == MAX - 1)
        printf("Queue Overflow\n");
    else {
        printf("Enter element: ");
        scanf("%d", &item);
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = item;
        printf("Inserted %d\n", item);
    }
}

void dequeue() {
    if (front == -1 || front > rear)
        printf("Queue Underflow\n");
    else {
        printf("Deleted %d\n", queue[front]);
        front++;
    }
}

void display() {
    if (front == -1 || front > rear)
        printf("Queue is Empty\n");
    else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    int choice;
    printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            enqueue();
        else if (choice == 2)
            dequeue();
        else if (choice == 3)
            display();
    } while (choice != 4);

    return 0;
}

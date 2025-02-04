#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* front = NULL;
node* rear = NULL;

int isEmpty() {
    return front == NULL;
}

void enqueue(int value) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = value;
    temp->next = NULL;

    if (rear == NULL) { 
        front = temp;
        rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
    printf("Enqueued: %d\n", value);
}

void dequeue() {
    if (isEmpty()) {
        printf("Underflow! Queue is empty.\n");
        return;
    }
    node* temp = front;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    int value = temp->data;
    free(temp);
    printf("Dequeued: %d\n", value);
}

void peek() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }
    printf("The element at front of queue is: %d\n", front->data);
}

void size() {
    int count = 0;
    node* temp = front;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("The size of queue is: %d\n", count);
}

void display() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }
    node* temp = front;
    printf("The elements in queue are: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int ch, val;

    printf("Queue Operations Menu:\n");
    printf("Enqueue in queue\n");
    printf("Dequeue from queue\n");
    printf("Peek into queue\n");
    printf("Check if the queue is empty\n");
    printf("Get the size of queue\n");
    printf("Display queue\n");
    printf("Exit\n");

    while (1) {
        printf("Enter your choice (1-7): ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value to enqueue: ");
                if (scanf("%d", &val) != 1) {
                    printf("Invalid input. Only enter an integer.\n");
                    while (getchar() != '\n');
                    break;
                }
                enqueue(val);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                if (isEmpty()) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;

            case 5:
                size();
                break;

            case 6:
                display();
                break;

            case 7:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    }
    return 0;
}
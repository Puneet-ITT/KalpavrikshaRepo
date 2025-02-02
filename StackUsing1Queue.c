#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Queue {
    int array[MAX];
    int front, rear;
};

void initializeQueue(struct Queue* q) {
    q->front = 0;
    q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return (q->front > q->rear);
}

int isFull(struct Queue* q) {
    return (q->rear == MAX - 1);
}

void enqueue(struct Queue* q, int data) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    q->array[++(q->rear)] = data;
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->array[(q->front)++];
}

void push(struct Queue* q, int data) {
    enqueue(q, data);
    int n = q->rear - q->front;
    for (int i = 0; i < n; i++) {
        enqueue(q, dequeue(q));
    }
}

int pop(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return dequeue(q);
}

int peek(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return q->array[q->front];
}

void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements:\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d\n", q->array[i]);
    }
}

int main() {
    struct Queue q;
    initializeQueue(&q);
    
    int ch, val;
    
    printf("Stack using Queue Operations Menu:\n");
    printf("Push into stack\n");
    printf("Pop from stack\n");
    printf("Peek into stack\n");
    printf("Display stack\n");
    printf("Exit\n");

    while (1) {
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value to push: ");
                if (scanf("%d", &val) != 1) {
                    printf("Invalid input. Only enter an integer.\n");
                    while (getchar() != '\n'); 
                    break;
                }
                push(&q, val);
                break;

            case 2:
                printf("Popped element: %d\n", pop(&q));
                break;

            case 3:
                printf("top element: %d\n", peek(&q));
                break;

            case 4:
                display(&q);
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Please enter a valid choice (1-5).\n");
        }
    }

    return 0;
}
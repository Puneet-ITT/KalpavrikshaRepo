#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int *arr;
    int front;
    int rear;
    int size;
} Queue;

void initQueue(Queue *q) {
    q->size = 1000;
    q->front = -1;
    q->rear = -1;
    q->arr = (int*)malloc(q->size * sizeof(int));
}

int isFull(Queue *q) {
    return (q->rear == q->size - 1);
}

int isEmpty(Queue *q) {
    return (q->front == -1 || q->front > q->rear);
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d\n", value);
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->arr[q->rear] = value;
        printf("Enqueued %d\n", value);
    }
}

void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
    } else {
        printf("Dequeued %d\n", q->arr[q->front]);
        q->front++;
    }
}

void peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot peek.\n");
    } else {
        printf("Front element is %d\n", q->arr[q->front]);
    }
}

void size(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Size is 0.\n");
    } else {
        printf("Queue size is %d\n", q->rear - q->front + 1);
    }
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

int main() {

    Queue *q = (Queue*)malloc(sizeof(Queue));
    initQueue(q);

    int ch, val;
    printf("Queue Operations Menu:\n");
    printf("\t1. Enqueue (Add to queue)\n");
    printf("\t2. Dequeue (Remove from queue)\n");
    printf("\t3. Peek (View front element)\n");
    printf("\t4. Check if the queue is empty\n");
    printf("\t5. Get the size of the queue\n");
    printf("\t6. Display queue\n");
    printf("\t7. Exit\n");
    while (1) {

        printf("Enter your choice (1-7): ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value to enqueue: ");
                if (scanf("%d", &val) != 1) {
                    printf("Invalid input! Please enter an integer.\n");
                    while (getchar() != '\n');
                    break;
                }
                enqueue(q, val);
                break;

            case 2:
                dequeue(q);
                break;

            case 3:
                peek(q);
                break;

            case 4:
                if (isEmpty(q)) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;

            case 5:
                size(q);
                break;

            case 6:
                display(q);
                break;

            case 7:
                printf("Exiting...\n");
                free(q->arr);
                free(q);
                return 0;

            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }

    return 0;
}

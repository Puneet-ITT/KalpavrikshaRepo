#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int size;
    int topElement;
    int* arr;
} Stack;

void push(Stack* stack, int value) {
    stack->arr[++stack->topElement] = value;
}

int isEmpty(Stack* stack) {
    return stack->topElement == -1;
}

int isFull(Stack* stack) {
    return stack->topElement == stack->size - 1;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return stack->arr[stack->topElement--];
    }
}

void enqueue(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow! Cannot enqueue.\n");
    } else {
        stack->arr[++stack->topElement] = value;
    }
}

int dequeue(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        return stack->arr[stack->topElement--];
    }
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        return stack->arr[stack->topElement];
    }
}

int size(Stack* stack) {
    return stack->topElement + 1;
}

int main() {
    Stack stack;
    stack.size = 100;
    stack.topElement = -1;
    stack.arr = (int*)malloc(stack.size * sizeof(int));

    int choice, value;

    printf("Queue Operations Menu\n");
    printf("Enqueue into the queue\n");
    printf("Dequeue from the queue\n");
    printf("Peek into the Queue\n");
    printf("Check if Queue is Empty\n");
    printf("Get the size of Queue\n");
    printf("Exit\n");
    while (1) {
        printf("Enter your Choice(1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to Enqueue: ");
                scanf("%d", &value);
                enqueue(&stack, value);
                break;

            case 2:
                value = dequeue(&stack);
                if (value != -1) {
                    printf("Dequeued value: %d\n", value);
                }
                break;

            case 3:
                value = peek(&stack);
                if (value != -1) {
                    printf("Front element: %d\n", value);
                }
                break;

            case 4:
                if (isEmpty(&stack)) {
                    printf("The Queue is empty.\n");
                } else {
                    printf("The Queue is not empty.\n");
                }
                break;

            case 5:
                printf("Size of the Queue is: %d\n", size(&stack));
                break;

            case 6:
                printf("Exiting...\n");
                free(stack.arr);
                return 0;

            default:
                printf("Invalid Choice. Please enter a valid input.\n");
        }
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct Queue{
    Node* stack1;
    Node* stack2;
}Queue;

void push(Node** topElement, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL){
        printf("Stack overflow\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = *topElement;
    *topElement = newNode;
}

int pop(Node** topElement){
    int result;
    Node* top;
    if(*topElement == NULL){
        printf("Stack underflow\n");
        exit(0);
    }else{
        top = *topElement;
        result = top->data;
        *topElement = top->next;
        free(top);
        return result;
    }
}

int isEmpty(Queue* queue){
    return (queue->stack1 == NULL && queue->stack2 == NULL);
}

void enQueue(Queue* queue, int data){
    push(&queue->stack1, data);
}

int deQueue(Queue* queue){
    int data;
    if(isEmpty(queue)){
        printf("Queue is empty\n");
        return -1;
    }
    if(queue->stack2 == NULL){
        while(queue->stack1 != NULL){
            data = pop(&queue->stack1);
            push(&queue->stack2, data);
        }
    }
    data = pop(&queue->stack2);
    return data;
}

int front(Queue* queue){
    int data;
    if(isEmpty(queue)){
        printf("Queue is empty\n");
        return -1;
    }
    if(queue->stack2 == NULL){
        while(queue->stack1 != NULL){
            data = pop(&queue->stack1);
            push(&queue->stack2, data);
        }
    }
    return queue->stack2->data;
}

int size(Queue* queue){
    int size = 0;
    Node* temp = queue->stack1;

    while(temp != NULL){
        size++;
        temp = temp->next;
    }
    temp = queue->stack2;
    while(temp != NULL){
        size++;
        temp = temp->next;
    }
    return size;
}

int main(){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->stack1 = NULL;
    queue->stack2 = NULL;

    int ch,value;

    printf("Queue Operations Menu\n");
    printf("\t1. Enqueue into the queue\n");
    printf("\t2. Dequeue from the queue\n");
    printf("\t3. Peek into the Queue\n");
    printf("\t4. Check if Queue is Empty\n");
    printf("\t5. Get the size of Queue\n");
    printf("\t6. Exit\n");
    while(1){
        printf("Enter your Choice(1-6): ");
        scanf("%d", &ch);

        switch(ch){
            case 1:
                printf("Enter value to Enqueue: ");
                scanf("%d", &value);
                enQueue(queue, value);
                printf("Enqueued %d into the queue.\n", value);
                break;

            case 2:
                value = deQueue(queue);
                if(value != -1){
                    printf("Dequeued value: %d\n", value);
                }
                break;

            case 3:
                value = front(queue);
                if(value != -1) {
                    printf("Front element: %d\n", value);
                }
                break;

            case 4:
                if(isEmpty(queue)){
                    printf("The Queue is empty.\n");
                }else{
                    printf("The Queue is not empty.\n");
                }
                break;

            case 5:
                printf("Size of the Queue is: %d\n", size(queue));
                break;

            case 6:
                printf("Exiting...\n");
                free(queue);
                return 0;

            default:
                printf("Invalid Choice. Please enter a valid input.\n");
        }
    }
    return 0;
}
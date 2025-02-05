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

void push(struct Queue* q1, struct Queue* q2, int data) {
   enqueue(q2, data);
   while (!isEmpty(q1)) {
       enqueue(q2, dequeue(q1));
   }
   struct Queue temp = *q1;
   *q1 = *q2;
   *q2 = temp;
}

int pop(struct Queue* q1) {
   if (isEmpty(q1)) {
       printf("Stack is empty!\n");
       return -1;
   }
   return dequeue(q1);
}

int peek(struct Queue* q1) {
   if (isEmpty(q1)) {
       printf("Stack is empty!\n");
       return -1;
   }
   return q1->array[q1->front];
}

void display(struct Queue* q1) {
   if (isEmpty(q1)) {
       printf("Stack is empty!\n");
       return;
   }
   printf("Stack elements:\n");
   for (int i = q1->front; i <= q1->rear; i++) {
       printf("%d\n", q1->array[i]);
   }
}

int main() {
   struct Queue q1, q2;
   initializeQueue(&q1);
   initializeQueue(&q2);
   
   int choice, value;

   while (1) {
       printf("\nStack Using Two Queues Menu:\n");
       printf("\t1. Push into stack\n");
       printf("\t2. Pop from stack\n");
       printf("\t3. Peek into stack\n");
       printf("\t4. Display stack\n");
       printf("\t5. Exit\n");

       printf("Enter your choice (1-5): ");
       if (scanf("%d", &choice) != 1) {
           printf("Invalid input. Please enter a number between 1 and 5.\n");
           while (getchar() != '\n');
           continue;
       }

       switch (choice) {
           case 1:
               printf("Enter value to push: ");
               if (scanf("%d", &value) != 1) {
                   printf("Invalid input. Only enter an integer.\n");
                   while (getchar() != '\n');
                   break;
               }
               push(&q1, &q2, value);
               printf("Pushed %d into stack.\n", value);
               break;

           case 2:
               value = pop(&q1);
               if (value != -1) {
                   printf("Popped element: %d\n", value);
               }
               break;

           case 3:
               value = peek(&q1);
               if (value != -1) {
                   printf("Peek/top element: %d\n", value);
               }
               break;

           case 4:
               display(&q1);
               break;

           case 5:
               printf("Exiting...\n");
               return 0;

           default:
               printf("Invalid choice. Please select a valid option (1-5).\n");
       }
   }

   return 0;
}

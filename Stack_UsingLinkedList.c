#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}node;

node* head = NULL;

int isEmpty(){
    return head == NULL;
}

void push(int value){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = value;
    temp->next = head;
    head = temp;
    printf("Pushed: %d\n", value);
}

void pop(){
    if (isEmpty()){
        printf("Underflow! Stack is empty.\n");
        return; 
    } else {
        node* temp = head;
        head = head->next;
        int value = temp->data;
        free(temp);
        printf("Popped: %d\n", value);
    }
}

void peek(){
    if (isEmpty()){
        printf("Stack is Empty\n");
        return; 
    }
    printf("The element at top of stack is: %d\n", head->data);
}

void size(){
    int count = 0;
    node* temp = head;
    while (temp != NULL){
        count++;
        temp = temp->next;
    }
    printf("The size of stack is: %d\n", count);
}

void display(){
    if (isEmpty()){
            printf("Stack is Empty\n");
            return; 
    }
    node* temp = head;
    printf("The elements of array are: ");
    while (temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    int ch, val;
    
    printf("Stack Operations Menu:\n");
    printf("Push in stack\n");
    printf("Pop from  stack\n");
    printf("Peek into stack\n");
    printf("Check if the stack is empty\n");
    printf("Get the size of stack\n");
    printf("Display stack\n");
    printf("Exit\n");

    while (1) {
        printf("Enter your choice (1-6): ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value to push: ");
                if (scanf("%d", &val) != 1) {
                    printf("Invalid input. only enter an integer.\n");
                    while (getchar() != '\n');
                    break;
                }
                push(val);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                if(isEmpty()){
                    printf("Stack is empty.\n");
                }else{
                    printf("Stack is not empty.\n");
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
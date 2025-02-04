#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int size;
    int top;
    int *arr;
}stack;

int isFull(stack* s){
    return s->top==s->size-1;
}

int isEmpty(stack* s){
    return s->top==-1;
}

void display(stack* s){
    printf("The elements of stack are: ");
    for(int i=0; i<=s->top; i++)
        printf("%d ", s->arr[i]);
    printf("\n");
}

void push(stack* s, int val){
    if(isFull(s))
        printf("Overflowed! Stack is full.\n");
    else{
        s->arr[++s->top]=val;
        printf("Pushed: %d\n", val);
    }
}

void pop(stack* s){
    if(isEmpty(s))
        printf("Underflow! Stack is empty.\n");
    else{
        printf("Popped value: %d\n", s->arr[s->top--]);
    }
}

void peek(stack* s){
    if(isEmpty(s))
        printf("Stack is empty.\n");
    else{
        printf("On top of stack is: %d\n", s->arr[s->top]);
    }
}

void size(stack* s){
    printf("Size of the stack is: %d\n", s->top+1);
}

int main(){
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    stack* s=(stack*)malloc(sizeof(stack));
    s->size=n;
    s->top=-1;
    s->arr=(int*)malloc(s->size*sizeof(int));
    
    printf("Stack Operations Menu:\n");
    printf("Push in stack\n");
    printf("Pop from  stack\n");
    printf("Peek into stack\n");
    printf("Check if the stack is empty\n");
    printf("Get the size of stack\n");
    printf("Display stack\n");
    printf("Exit\n");

    int ch, val;
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
                push(s, val);
                break;

            case 2:
                pop(s);
                break;

            case 3:
                peek(s);
                break;

            case 4:
                if(isEmpty(s)){
                    printf("Stack is empty.\n");
                }else{
                    printf("Stack is not empty.\n");
                }
                break;

            case 5:
                size(s);
                break;

            case 6:
                display(s);
                break;

            case 7:
                printf("Exiting...\n");
                free(s->arr);
                return 0;

            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    }
    return 0;
}
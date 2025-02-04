#include <stdio.h>
#include <stdlib.h>
#define Size 1000
int count=0;
 
typedef struct stack
{
    int top;
    int capacity;
    int *arr;
}stack;
 
stack *createStack(int capacity)
{
 
    stack *stack = malloc(sizeof(stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = malloc(capacity * sizeof(int));
    return stack;
}
 
int isfull(stack *s, int capacity)
{
    return s->top == capacity - 1;
}
 
int isempty(stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}
void push(stack *s1,int val)
{
 
    if (isfull(s1, Size))
    {
        printf("Stack is Full\n");
        return;
    }
    s1->arr[++s1->top] = val;
}
 
int  pop(stack *s1)
{
    if (isempty(s1))
    {
        printf("Stack is Empty\n");
        return -1;
    }
    return s1->arr[s1->top--];
}
 
void enqueue(stack* s,int  val){
    push(s,val);
    count++;
}
 
 
int dequeue(stack* s) {
   if (isempty(s)) {
       printf("Queue is empty\n");
       return -1;
   }
   int x = pop(s);  
   if (isempty(s)) {
       return x;
   }
   int item = dequeue(s);
   push(s,x);  
   return item;
}
 
 
void display(stack* s){
    printf("Queue elements : \n");
        for(int i=0;i<=s->top;i++){
            printf("%d ",s->arr[i]);
        }
    printf("\n");
}
 
void frontElement(stack *s) {
    if (isempty(s)) {
        printf("Queue is Empty\n");
        return;
    }
    int x=dequeue(s);
    printf("Front Element %d\n: ",x);
    enqueue(s,x);
}
void rearElement(stack *s) {
    if (isempty(s)) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Rear Element: %d\n", s->arr[s->top]);
}
 
int main()
{
     stack* s = createStack(Size);

 
    while (1)
    {
        int ch;
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Front Element\n");
        printf("4.Rear Element\n");
        printf("5.show\n");
        printf("6.Exit\n");
        printf("Enter Choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
             int val;
            printf("Enter value to enqueue: ");
             scanf("%d", &val);
             enqueue(s, val);
            break;
        case 2:
        int data=dequeue(s);
        if(data!=-1){
            printf("Dequed: %d\n",data);
        }
            break;
        case 3:
            frontElement(s);
            break;
        case 4:
            rearElement(s);
            break;
        case 5:
 
            display(s);
            break;
        case 6:
            break;
        default:
            printf("invalid choice\n");
            break;
        }
        if (ch == 6)
        {
            return 0;
        }
    }
 
    return 0;
}
 

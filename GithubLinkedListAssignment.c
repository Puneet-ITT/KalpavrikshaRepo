#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

node* head = NULL;

void insertAtBeginning(int x){
    node* ptr = (node*)malloc(sizeof(node));
    ptr->data= x;
    ptr->next= head;
    head=ptr;
}

void insertAtPosition(int pos, int x){
    if(pos<1){
        printf("Invalid position\n");
        return;
    }
    node* ptr=(node*)malloc(sizeof(node));
    ptr->data=x;
    ptr->next=NULL;
    
    if(pos==1){
        ptr->next=head;
        head=ptr;
        return;
    }
    
    node* temp=head;
    for(int i=1; temp !=NULL && i<pos-1; i++){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Invalid postion\n");
        return;
    }
    
    ptr->next=temp->next;
    temp->next=ptr;
}

void insertAtEnd(int x){
    node* ptr=(node*)malloc(sizeof(node));
    ptr->data=x;
    ptr->next=NULL;
    
    if(head==NULL){
        head=ptr;
        return;
    }
    
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=ptr;
}

void display(){
    if (head == NULL){
        printf("List is empty.\n");
        return;
    }
    node* curr = head;
    while(curr != NULL){
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void updateAtPosition(int pos, int x){
    if(pos<1){
        printf("Invalid position\n");
        return;
    }
    node* temp=head;
    
    for(int i=1; temp!=NULL && i<pos; i++){
        temp=temp->next;
    }
    
    if(temp==NULL){
        printf("Invalid position\n");
        return;
    }
    
    temp->data=x;
}

void deleteAtBeginning(){
    if(head==NULL){
        printf("Invalid: List is empty\n");
        return;
    }
    node *temp=head;
    head = head->next;
    free(temp);
}

void deleteAtEnd(){
    if (head == NULL) {
        printf("Invalid position\n");
        return;
    }

    if (head->next == NULL) {
        head = NULL;
        free(head);
        return;
    }
    
    node* temp=head;
    while(temp->next != NULL  && temp->next->next != NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
}
void deleteAtPosition(int pos){
    if (pos < 1 || head == NULL) {
        printf("Invalid position\n");
        return;
    }
    node* ptr = head;
    if (pos == 1) {
        head = head->next;
        free(ptr);
        return;
    }
    for(int i=1; i<pos-1; i++){
        ptr=ptr->next;
    }
    
    node* ptr2 = ptr->next;
    ptr->next=ptr2->next;
    free(ptr2);
}

int main(){
    int n;
    printf("Enter number of method to be performed: ");
    do {
        scanf("%d", &n);
        if (n < 1 || n > 100) {
            printf("Invalid! Enter between 1 and 100: ");
        }
    } while (n < 1 || n > 100);
    
    int i=0;
    while(i<n){
        printf("\n1. insert at end.\n");
        printf("2. insert at beginning.\n");
        printf("3. insert at position.\n");
        printf("4. display all.\n");
        printf("5. update at position.\n");
        printf("6. delete the first element.\n");
        printf("7. delete the last element.\n");
        printf("8. delete at position.\n");
        int ch;
        scanf("%d", &ch);
        
        int x, pos;
        
        switch(ch){
            case 1:
                scanf("%d", &x);
                insertAtEnd(x);
                break;
            case 2:
                scanf("%d", &x);
                insertAtBeginning(x);
                break;
            case 3:
                scanf("%d %d", &pos, &x);
                insertAtPosition(pos, x);
                break;
            case 4:
                display();
                break;
            case 5:
                scanf("%d %d", &pos, &x);
                updateAtPosition(pos, x);
                break;
            case 6:
                deleteAtBeginning();
                break;
            case 7:
                deleteAtEnd();
                break;
            case 8:
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
        
        i++;
    }
    return 0;
}
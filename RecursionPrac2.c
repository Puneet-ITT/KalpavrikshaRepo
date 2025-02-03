#include <stdio.h>
#include <stdlib.h>
 
typedef struct node
{
    int data;
    struct node *next;
}node;

node *head=NULL;


void print_reverse_recursive (node *head)
{
    if (head == NULL)
    {
        return;
    }
    //  head = head->next;
    print_reverse_recursive (head->next);
    printf ("%d ", head -> data);
}
 
void print (node *head_ref)
{
    if (head_ref == NULL)
    {
        return;
    }
    printf ("%d ", head_ref -> data);
    print (head_ref->next);
}

void insert_new_node (int new_data)
{
    node * new_node = (node *) malloc (sizeof (node));
    new_node -> data = new_data;
    new_node -> next = head;
    head = new_node;
}

int main ()
{
    for(int i=1;i<10;i++){
    insert_new_node (i);
    }
    printf ("LinkedList : ");
    node *head_ref=head;
    print(head_ref);
    printf ("\nLinkedList in reverse order : ");
    
    print_reverse_recursive (head);
    printf ("\n");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
 
typedef struct node
{
    int data;
    struct node *next;
}node;

node *head=NULL;
 
void generate(int num)
{
    int i;
    node *temp;
 
    for (i = 0; i < num; i++)
    {
        temp = (node *)malloc(sizeof(node));
        temp->data = rand() % num;
        printf("%d  ", temp->data);
        if (head == NULL)
        {
            head = temp;
            head->next = NULL;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
    }
}
 
void search(int key, int index)
{
    if (head->data == key)
    {
        printf("Key found at Position: %d\n", index);
    }
    if (head->next == NULL)
    {
        return;
    }
    head=head->next;
    search(key, index - 1);
}

int main()
{
    int key, num;
    printf("Enter the number of nodes: ");
    scanf("%d", &num);
    generate(num);
    printf("\nEnter key to search: ");
    scanf("%d", &key);
    search(key, num);
}
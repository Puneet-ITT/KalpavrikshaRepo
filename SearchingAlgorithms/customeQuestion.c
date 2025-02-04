// C program Implements locality of reference in Link list.The found element in a linked list moves to the front as soon as it is found.

/*Sample Input/Output

1. Insert
2. Print
3. Find
4. Exit
Enter choice:1
Enter Data:1
Enter choice:1
Enter Data:2
Enter choice:1
Enter Data:3
Enter choice:2
The list is 1 2 3 
 
Enter choice:3
Enter element to be searched:2
Element  found
Enter choice:2
The list is 2 1 3 
 
Enter choice:4
Exit
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} node;

node *head = NULL;

void insert(int data) {
    node *newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int find(int key) {
    node *temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found\n", key);
            return key;
        }
        temp = temp->next;
    }
    printf("Element %d not found\n", key);
    return -1;
}

void insertStart(int data) {
    node *newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void delete(int data) {
    node *ptr2;
    if(head->data==data){
        head=head->next;
        return;
    }
    for (ptr2 = head; ptr2 != NULL; ptr2 = ptr2->next) {
        if (ptr2->next->data == data) {
            ptr2->next = ptr2->next->next;
            return;
        }
    }
}

void print() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int query, data, t;

    while (1) {
        printf("\n1. Insert\n");
        printf("2. Print\n");
        printf("3. Find\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &query);

        switch (query) {
            case 1:
                printf("Enter Data: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                printf("The list is: ");
                print();
                break;
            case 3:
                printf("Enter element to be searched: ");
                scanf("%d", &data);
                t = find(data);
                if (t != -1) {
                    delete(t);
                    insertStart(t);
                }
                break;
            case 4:
                printf("Exit\n");
                exit(0);
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}

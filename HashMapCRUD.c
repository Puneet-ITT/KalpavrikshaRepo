#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct Node {
    int key;
    int value;
    struct Node *next;
} node;

typedef struct HashMap {
    node* table[TABLE_SIZE];
} HashMap;

node* createNode(int key, int val) {
    node *ptr = (node*)malloc(sizeof(node));
    ptr->key = key;
    ptr->value = val;
    ptr->next = NULL;
    return ptr;
}

int hash(int key) {
    return key % TABLE_SIZE;
}

void initHashTable(HashMap* map) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        map->table[i] = NULL;
    }
}

void insert(HashMap* map, int key, int value) {
    int index = hash(key);
    node *ptr = createNode(key, value);

    if (map->table[index] == NULL) {
        map->table[index] = ptr;
    } 
    else {
        node *temp = map->table[index];
        while(temp != NULL) {
            if(temp->key == key) {
                temp->value = value;
                free(ptr);
                return;
            }
            temp = temp->next;
        }
        ptr->next = map->table[index];
        map->table[index] = ptr;
    }
    printf("Key %d inserted with value %d.\n", key, value);
}

void search(HashMap* map, int key) {
    int index = hash(key);
    node *temp = map->table[index];
    while (temp != NULL) {
        if (temp->key == key) {
            printf("Value: %d\n", temp->value);
            return;
        }
        temp = temp->next;
    }
    printf("Key %d not found.\n", key);
}

void delete(HashMap* map, int key) {
    int index = hash(key);
    node* curr = map->table[index];
    node* prev = NULL;

    while (curr != NULL) {
        if (curr->key == key) {
            if (prev == NULL) {
                map->table[index] = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            printf("Key %d deleted.\n", key);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Key %d not found.\n", key);
}

void DisplayList(HashMap* map) {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        node* ptr = map->table[i];
        if (ptr != NULL) {
            printf("Index %d: ", i);
            while (ptr != NULL) {
                printf("(%d, %d ) \n ", ptr->key, ptr->value);
                ptr = ptr->next;
            }
            
        }
    }
}

int main() {
    HashMap map;
    initHashTable(&map);
    int ch, key, value;

    printf("Operations\n");
    while (1) {
        printf("1. Insert \n");
        printf("2. Search \n");
        printf("3. Delete \n");
        printf("4. Display \n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter value: ");
                scanf("%d", &value);
                insert(&map, key, value);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(&map, key);
                break;
            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                delete(&map, key);
                break;
            case 4:
                DisplayList(&map);
                break;
            case 5:
                printf("Program Ended.\n");
                return 0;
            default:
                printf("Enter Valid Choice.\n");
        }
    }

    return 0;
}
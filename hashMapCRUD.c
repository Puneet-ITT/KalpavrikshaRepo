#include <stdio.h>
#include <stdlib.h>

#define tableSize 10

typedef struct Node {
    int key;
    int value;
    struct Node *next;
} Node;

typedef struct HashMap {
    Node* table[tableSize];
} HashMap;

// Function to create a new node
Node* createNode(int key, int val) {
    Node* ptr = (Node*)malloc(sizeof(Node));
    ptr->key = key;
    ptr->value = val;
    ptr->next = NULL;
    return ptr;
}

int hash(int key) {
    return key % tableSize;
}

void hashInit(HashMap* map) {
    for (int i = 0; i < tableSize; i++) {
        map->table[i] = NULL;
    }
}

void insert(HashMap* map, int key, int value) {
    int index = hash(key);
    Node* ptr = createNode(key, value);

    if (map->table[index] == NULL) {
        map->table[index] = ptr;
    } 
    else {
        Node* curr = map->table[index];
        while(curr != NULL) {
            if(curr->key == key) {
                curr->value = value;
                free(ptr);
                return;
            }
            curr = curr->next;
        }
        ptr->next = map->table[index];
        map->table[index] = ptr;
    }
    printf("Key %d inserted with value %d.\n", key, value);
}

void search(HashMap* map, int key) {
    int index = hash(key);
    Node* curr = map->table[index];
    while (curr != NULL) {
        if (curr->key == key) {
            printf("Value: %d\n", curr->value);
            return;
        }
        curr = curr->next;
    }
    printf("Key %d not found.\n", key);
}

void delete(HashMap* map, int key) {
    int index = hash(key);
    Node* curr = map->table[index];
    Node* prev = NULL;

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

void display(HashMap* map) {
    printf("Hash Table:\n");
    for (int i = 0; i < tableSize; i++) {
        Node* curr = map->table[i];
        if (curr != NULL) {
            printf("Index %d: ", i);
            while (curr != NULL) {
                printf("(%d, %d) -> ", curr->key, curr->value);
                curr = curr->next;
            }
            printf("NULL\n");
        }
    }
}

int main() {
    HashMap map;
    hashInit(&map);
    int ch, key, value;

    printf("Hashmap operation\n");
    while (1) {
        printf("\t1. Insert (Put)\n");
        printf("\t2. Search (Get)\n");
        printf("\t3. Delete (Remove)\n");
        printf("\t4. Display\n");
        printf("\t5. Exit\n");
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
                printf("Enter key for delete: ");
                scanf("%d", &key);
                delete(&map, key);
                break;
            case 4:
                display(&map);
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

// Initialize hash table with -1 (indicating empty)
void init() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

// Hash function
int hash(int key) {
    return key % SIZE;
}

// Insert using quadratic probing
void insert(int key) {
    int index = hash(key);
    int i = 0;
    int newIndex;

    while (i < SIZE) {
        newIndex = (index + i * i) % SIZE;
        if (hashTable[newIndex] == -1) {
            hashTable[newIndex] = key;
            printf("Inserted %d at index %d\n", key, newIndex);
            return;
        }
        i++;
    }
    printf("Hash table is full. Could not insert %d\n", key);
}

// Display the hash table
void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1)
            printf("Index %d: %d\n", i, hashTable[i]);
        else
            printf("Index %d: EMPTY\n", i);
    }
}

int main() {
    init();

    int choice, key;
    while (1) {
        printf("\n1. Insert\n2. Display\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
          
            case 2:
                display();
                break;
          
            case 3:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

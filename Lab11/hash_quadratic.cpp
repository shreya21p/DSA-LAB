//Program to implement Hash ADT using Quadratic Probing
#include <cstdio>
const int TABLE_SIZE = 10;
const int EMPTY = -1;
const int DELETED = -2;
class HashTable 
{
    private:
        int table[TABLE_SIZE];
    public:
    HashTable() 
    {
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i] = EMPTY;
    }
    int hash(int);
    void insert(int);
    void remove(int);
    void search(int);
    void display();
};
int main() 
{
    HashTable ht;
    int choice, key;
    do {
        printf("Hash Table(Quadratic Probing) Menu:\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
        case 1:
            printf("Enter key to insert: ");
            scanf("%d", &key);
            ht.insert(key);
            break;
        case 2:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            ht.remove(key);
            break;
        case 3:
            printf("Enter key to search: ");
            scanf("%d", &key);
            ht.search(key);
            break;
        case 4:
            ht.display();
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);
    return 0;
}
// Hash function:
int HashTable::hash(int key) 
{
    return key % TABLE_SIZE;
}
// Function to perform insertion:
void HashTable::insert(int key) 
{
    int index = hash(key);
    int i = 0;
    while (i < TABLE_SIZE) 
    {
        int newIndex = (index + i * i) % TABLE_SIZE;
        if (table[newIndex] == EMPTY || table[newIndex] == DELETED) 
        {
            table[newIndex] = key;
            printf("Inserted %d at index %d\n", key, newIndex);
            return;
        }
        i++;
    }
    printf("Hash table is full. Insertion failed.\n");
}
// Function to perform deletion:
void HashTable::remove(int key) 
{
    int index = hash(key);
    int i = 0;
    while (i < TABLE_SIZE) 
    {
        int newIndex = (index + i * i) % TABLE_SIZE;
        if (table[newIndex] == EMPTY) break;
        if (table[newIndex] == key) 
        {
            table[newIndex] = DELETED;
            printf("Deleted %d from index %d\n", key, newIndex);
            return;
        }
        i++;
    }
    printf("Key %d not found.\n", key);
}
// Function to perform search:
void HashTable::search(int key) 
{
    int index = hash(key);
    int i = 0;
    while (i < TABLE_SIZE) 
    {
        int newIndex = (index + i * i) % TABLE_SIZE;
        if (table[newIndex] == EMPTY) break;
        if (table[newIndex] == key) 
        {
            printf("Key %d found at index %d\n", key, newIndex);
            return;
        }
        i++;
    }
    printf("Key %d not found.\n", key);
}
// Function to display:
void HashTable::display() 
{
    printf("\nHash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        printf("%d --> ", i);
        if (table[i] == EMPTY)
            printf("EMPTY");
        else if (table[i] == DELETED)
            printf("DELETED");
        else
            printf("%d", table[i]);
        printf("\n");
    }
}

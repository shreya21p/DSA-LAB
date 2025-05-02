//Program to implement Hash ADT using Linear Probing
#include <cstdio>
const int TABLE_SIZE = 10;
class HashTable 
{
private:
    int table[TABLE_SIZE];
    bool occupied[TABLE_SIZE];
public:
    HashTable() 
    {
        for (int i = 0; i < TABLE_SIZE; i++) 
        {
            table[i] = -1;        
            occupied[i] = false;  
        }
    }
    int hashFunction(int key);
    void insert(int key);
    void remove(int key);
    void search(int key);
    void display();
};
int main() 
{
    HashTable ht;
    int choice, key;
    do {
        printf("Hash Table(Linear Probing) Menu:\n");
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
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);
    return 0;
}
// Helper function for hash:
int HashTable::hashFunction(int key) 
{
        return key % TABLE_SIZE;
}
// Function to perform insertion:
void HashTable::insert(int key) 
{
    int index = hashFunction(key);
    int startIndex = index;
    do {
        if (!occupied[index] || table[index] == -1) 
        {
            table[index] = key;
            occupied[index] = true;
            printf("Inserted %d at index %d\n", key, index);
            return;
        }
        index = (index + 1) % TABLE_SIZE;
    } while (index != startIndex);
    printf("Hash Table is full. Cannot insert %d\n", key);
}
// Function to perform deletion:
void HashTable::remove(int key) 
{
    int index = hashFunction(key);
    int startIndex = index;
    do {
        if (occupied[index] && table[index] == key) 
        {
            table[index] = -1;
            printf("Deleted %d from index %d\n", key, index);
            return;
        }
        index = (index + 1) % TABLE_SIZE;
    } while (index != startIndex);
    printf("Key %d not found in the hash table.\n", key);
}
// Function to perform search:
void HashTable::search(int key) 
{
    int index = hashFunction(key);
    int startIndex = index;
    do {
        if (occupied[index] && table[index] == key) 
        {
            printf("Key %d found at index %d\n", key, index);
            return;
        }
        index = (index + 1) % TABLE_SIZE;
    } while (occupied[index] && index != startIndex);
    printf("Key %d not found in the hash table.\n", key);
}
// Function to display:
void HashTable::display() 
{
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) 
    {
            if (occupied[i] && table[i] != -1)
                printf("%d --> %d\n", i, table[i]);
            else
                printf("%d --> EMPTY\n", i);
    }
}

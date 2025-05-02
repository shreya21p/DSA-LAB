//Program to implement Hash ADT using Separate Chaining
#include <cstdio>
#include <list>
#include <unordered_map>
#include <algorithm>
const int TABLE_SIZE = 10;
class HashTable 
{
private:
    std::unordered_map<int, std::list<int>> table;
public:
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
        printf("Hash Table(Separate Chaining)Menu:\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
        case 1:
            printf("Enter key to insert: ");
            scanf("%d", &key);
            ht.insert(key);
            ht.display();
            break;
        case 2:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            ht.remove(key);
            ht.display();
            break;
        case 3:
            printf("Enter key to search: ");
            scanf("%d", &key);
            ht.search(key);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);
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
    table[index].push_back(key);
    printf("Inserted %d at index %d\n", key, index);
}
// Function to perform deletion:
void HashTable::remove(int key) 
{
    int index = hash(key);
    auto& chain = table[index];
    auto it = std::find(chain.begin(), chain.end(), key);
    if (it != chain.end()) 
    {
        chain.erase(it);
        printf("Deleted %d from index %d\n", key, index);
    } 
    else 
    {
        printf("Key %d not found.\n", key);
    }
}
// Function to perform search:
void HashTable::search(int key) 
{
    int index = hash(key);
    auto& chain = table[index];
    if (std::find(chain.begin(), chain.end(), key) != chain.end()) 
    {
        printf("Key %d found at index %d\n", key, index);
    } 
    else 
    {
        printf("Key %d not found.\n", key);
    }
}
// Function to perform display:
void HashTable::display() 
{
    printf("\nHash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        printf("%d --> ", i);
        if (table.find(i) != table.end() && !table[i].empty()) 
        {
            for (int key : table[i]) 
            {
                printf("%d -> ", key);
            }
            printf("NULL");
        } 
        else 
        {
            printf("NULL");
        }
        printf("\n");
    }
}

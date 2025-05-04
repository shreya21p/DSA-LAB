// Program to implement a Priority Queue ADT using Max Heap with operations: insert, delete, display, search, and sort
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0 && heap[(index - 1) / 2] < heap[index]) {
            swap(heap[(index - 1) / 2], heap[index]);
            index = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] > heap[largest])
            largest = left;

        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    void deleteMax() {
        if (heap.empty()) {
            printf("Heap is empty.\n");
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    void display() {
        if (heap.empty()) {
            printf("Heap is empty.\n");
            return;
        }
        for (int val : heap)
            printf("%d ", val);
        printf("\n");
    }

    bool search(int value) {
        for (int val : heap) {
            if (val == value)
                return true;
        }
        return false;
    }

    void heapSort() {
        vector<int> tempHeap = heap;
        sort(tempHeap.rbegin(), tempHeap.rend());
        for (int val : tempHeap)
            printf("%d ", val);
        printf("\n");
    }
};

int main() {
    MaxHeap maxHeap;
    int choice, value;

    while (true) {
        printf("\nMenu:\n1. Insert\n2. Delete Max\n3. Display\n4. Search\n5. Sort (Heap Sort)\n6. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                maxHeap.insert(value);
                break;
            case 2:
                maxHeap.deleteMax();
                break;
            case 3:
                maxHeap.display();
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (maxHeap.search(value))
                    printf("Value found in heap.\n");
                else
                    printf("Value not found in heap.\n");
                break;
            case 5:
                maxHeap.heapSort();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

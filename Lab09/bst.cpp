// Program to implement binary search tree 
#include <cstdio>

class BST {
public:
    struct Node {
        int data;
        Node* left;
        Node* right;
    };

    Node* root;

    BST() { root = nullptr; }

    Node* insert(Node* root, int value);
    void preorder(Node* root);
    void inorder(Node* root);
    void postorder(Node* root);
    bool search(Node* root, int key);
    Node* createNode(int value);
};

int main() {
    BST tree;
    int choice, value;

    do {
        printf("\nBinary Search Tree Menu\n");
        printf("1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Search\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                tree.root = tree.insert(tree.root, value);
                break;
            case 2:
                printf("Preorder Traversal: ");
                tree.preorder(tree.root);
                printf("\n");
                break;
            case 3:
                printf("Inorder Traversal: ");
                tree.inorder(tree.root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                tree.postorder(tree.root);
                printf("\n");
                break;
            case 5:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (tree.search(tree.root, value))
                    printf("%d found in the tree.\n", value);
                else
                    printf("%d not found in the tree.\n", value);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// Function to create a new node
BST::Node* BST::createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to insert a node into the BST
BST::Node* BST::insert(Node* root, int value) {
    if (root == nullptr)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Preorder traversal (Root-Left-Right)
void BST::preorder(Node* root) {
    if (root != nullptr) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Inorder traversal (Left-Root-Right)
void BST::inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Postorder traversal (Left-Right-Root)
void BST::postorder(Node* root) {
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Function to search for a value in BST
bool BST::search(Node* root, int key) {
    if (root == nullptr)
        return false;
    if (root->data == key)
        return true;
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

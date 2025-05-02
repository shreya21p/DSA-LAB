//Program to implement binary tree
#include <stdlib.h>

class BinaryTree {

private:

struct Node {

    char data;

    struct Node* left;

    struct Node* right;

};



Node* root;


//Function to create new node
Node* createNode(char data) {

    Node* newNode = (Node*)malloc(sizeof(Node));

    if (!newNode) {

        printf("Memory allocation failed\n");

        return NULL;

    }

    newNode->data = data;

    newNode->left = NULL;

    newNode->right = NULL;

    return newNode;

}


//Function to preorder
void preorder(Node* node) {

    if (node == NULL) return;

    printf("%c ", node->data);

    preorder(node->left);

    preorder(node->right);

}


//Function for inorder traversal
void inorder(Node* node) {

    if (node == NULL) return;

    inorder(node->left);

    printf("%c ", node->data);

    inorder(node->right);

}


//Function for postorder
void postorder(Node* node) {

    if (node == NULL) return;

    postorder(node->left);

    postorder(node->right);

    printf("%c ", node->data);

}



Node* insert(Node* node, char data) {

    if (node == NULL) return createNode(data);

    

    char direction;

    printf("Insert %c to (L)eft or (R)ight of %c? ", data, node->data);

    scanf(" %c", &direction);



    if (direction == 'L' || direction == 'l')

        node->left = insert(node->left, data);

    else

        node->right = insert(node->right, data);



    return node;

}



int search(Node* node, char key) {

    if (node == NULL) return 0;

    if (node->data == key) return 1;

    return search(node->left, key) || search(node->right, key);

}

public:

BinaryTree() {

    root = NULL;

}



void insert(char data) {

    root = insert(root, data);

}



void preorder() {

    printf("Preorder: ");

    preorder(root);

    printf("\n");

}



void inorder() {

    printf("Inorder: ");

    inorder(root);

    printf("\n");

}



void postorder() {

    printf("Postorder: ");

    postorder(root);

    printf("\n");

}



void search(char key) {

    if (search(root, key))

        printf("Element %c found in the tree\n", key);

    else

        printf("Element %c not found in the tree\n", key);

}

};

int main() {

BinaryTree tree;

int choice;

char data;



while (1) {

    printf("\n1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Search\n6. Exit\nEnter choice: ");

    scanf("%d", &choice);



    switch (choice) {

        case 1:

            printf("Enter character to insert: ");

            scanf(" %c", &data);

            tree.insert(data);

            break;

        case 2:

            tree.preorder();

            break;

        case 3:

            tree.inorder();

            break;

        case 4:

            tree.postorder();

            break;

        case 5:

            printf("Enter character to search: ");

            scanf(" %c", &data);

            tree.search(data);

            break;

        case 6:

            printf("Exiting program.\n");

            return 0;

        default:

            printf("Invalid choice! Try again.\n");

    }

}

}

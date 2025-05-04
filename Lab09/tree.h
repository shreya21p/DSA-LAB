// Header file for BST expression tree 
#ifndef BST_H
#define BST_H

#include <cstdio>
#include <stack>
#include <cctype>
#include <string>
using namespace std;

class BST {
public:
    struct TreeNode {
        char value;
        TreeNode* left;
        TreeNode* right;
        TreeNode(char val) : value(val), left(NULL), right(NULL) {}
    };

    TreeNode* root;

    BST() { root = nullptr; }

    void preorder(TreeNode* root);
    void inorder(TreeNode* root);
    void postorder(TreeNode* root);
    void constructTree(string postfix);
};

// Preorder traversal (Root-Left-Right)
void BST::preorder(TreeNode* root) {
    if (root != nullptr) {
        printf("%c ", root->value);
        preorder(root->left);
        preorder(root->right);
    }
}

// Inorder traversal (Left-Root-Right)
void BST::inorder(TreeNode* root) {
    if (root != nullptr) {
        inorder(root->left);
        printf("%c ", root->value);
        inorder(root->right);
    }
}

// Postorder traversal (Left-Right-Root)
void BST::postorder(TreeNode* root) {
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->value);
    }
}

// Construct expression tree from postfix
void BST::constructTree(string postfix) {
    stack<TreeNode*> st;
    for (char ch : postfix) {
        if (isalnum(ch)) {
            st.push(new TreeNode(ch));
        } else {
            TreeNode* node = new TreeNode(ch);
            node->right = st.top(); st.pop();
            node->left = st.top(); st.pop();
            st.push(node);
        }
    }
    root = st.top();
}

#endif

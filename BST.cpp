/*
Theory:
    A Binary Search Tree (BST) is a binary tree in which each node has at most two children, and for each node, all the values 
    in the left subtree are less than the node's value, and all the values in the right subtree are greater than the node's value.

Complexities:

    Time Complexity:
        Best Case: O(log?n)O(logn) 
        Worst Case: O(n)O(n) for 
        Average Case: O(log?n)O(logn) 
        O(n)O(n) for storing nn elements in the tree.
*/

#include <iostream>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};

Node* newNode(int item) {
    Node* temp = new Node();
    temp->key = item;
    temp->left = temp->right = nullptr;
    return temp;
}

void inorder(Node* root, int& total_steps) {
    if (root != nullptr) {
        inorder(root->left, total_steps);
        total_steps++;
        cout << root->key << " ";
        inorder(root->right, total_steps);
    }
}

Node* insert(Node* root, int key, int& total_steps) {
    if (root == nullptr) {
        return newNode(key);
    }

    total_steps++;
    if (key < root->key) {
        root->left = insert(root->left, key, total_steps);
    } else if (key > root->key) {
        root->right = insert(root->right, key, total_steps);
    }

    return root;
}

Node* search(Node* root, int key, int& total_steps) {
    if (root == nullptr || root->key == key) {
        total_steps++;
        return root;
    }

    total_steps++;
    if (root->key < key) {
        return search(root->right, key, total_steps);
    }

    return search(root->left, key, total_steps);
}

Node* deleteNode(Node* root, int key, int& total_steps) {
    if (root == nullptr) {
        return root;
    }

    total_steps++;
    if (key < root->key) {
        root->left = deleteNode(root->left, key, total_steps);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key, total_steps);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = root->right;
        while (temp->left != nullptr) {
            temp = temp->left;
            total_steps++;
        }

        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key, total_steps);
    }

    return root;
}

int main() {
    Node* root = nullptr;
    int total_steps = 0;

    root = insert(root, 5, total_steps);
    insert(root, 3, total_steps);
    insert(root, 2, total_steps);
    insert(root, 4, total_steps);
    insert(root, 7, total_steps);
    insert(root, 6, total_steps);
    insert(root, 8, total_steps);

    inorder(root, total_steps);
    cout << endl;

    int key_to_search = 6;
    Node* result = search(root, key_to_search, total_steps);
    if (result != nullptr) {
        cout << "Key " << key_to_search << " found in the BST." << endl;
    } else {
        cout << "Key " << key_to_search << " not found in the BST." << endl;
    }

    int key_to_delete = 3;
    root = deleteNode(root, key_to_delete, total_steps);
    inorder(root, total_steps);
    cout << endl;

    cout << "Total number of steps: " << total_steps << endl;

    return 0;
}

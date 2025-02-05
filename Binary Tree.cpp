
/*
Beginning with an empty binary search tree, Construct binary search tree by inserting the values in the order given. 
  After constructing a binary tree -
  i. Insert new node,
  ii. Find number of nodes in longest path from root, 
  iii. Minimum data value found in the tree, 
  iv.Change a tree so that the roles of the left and right pointers are swapped at every node,
  v. Search a value */
  


#include <iostream>
#include <algorithm>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree() {
        root = nullptr;
    }

 
    void insert(int data) {
        root = insertHelper(root, data);
    }

    
    Node* insertHelper(Node* node, int data) {
        if (node == nullptr) {
            return new Node(data);
        }
        if (data < node->data) {
            node->left = insertHelper(node->left, data);
        } else {
            node->right = insertHelper(node->right, data);
        }
        return node;
    }

   
    int longestPathFromRoot() {
        return findLongestPath(root);
    }

    int findLongestPath(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        int leftPath = findLongestPath(node->left);
        int rightPath = findLongestPath(node->right);
        return max(leftPath, rightPath) + 1;
    }

   
    int findMin() {
        Node* temp = root;
        while (temp && temp->left != nullptr) {
            temp = temp->left;
        }
        return temp ? temp->data : -1;  
    }

   
    void swapChildren() {
        swapChildrenHelper(root);
    }

    void swapChildrenHelper(Node* node) {
        if (node == nullptr) {
            return;
        }
        swap(node->left, node->right);
        swapChildrenHelper(node->left);
        swapChildrenHelper(node->right);
    }

    
    bool search(int data) {
        return searchHelper(root, data);
    }

    bool searchHelper(Node* node, int data) {
        if (node == nullptr) {
            return false;
        }
        if (node->data == data) {
            return true;
        }
        if (data < node->data) {
            return searchHelper(node->left, data);
        } else {
            return searchHelper(node->right, data);
        }
    }

   
    void inorderTraversal(Node* node) {
        if (node == nullptr) {
            return;
        }
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

    
    void printTree() {
        inorderTraversal(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;

 
    int n;
    cout << "Enter the number of elements to insert into the BST: ";
    cin >> n;

   
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        bst.insert(value);
    }

    
    cout << "Original Tree (Inorder Traversal): ";
    bst.printTree();

    
    int choice;
    do {
        cout << "\nChoose an operation:\n";
        cout << "1. Insert a new node\n";
        cout << "2. Find the longest path from root\n";
        cout << "3. Find the minimum value\n";
        cout << "4. Swap left and right children at every node\n";
        cout << "5. Search for a value\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int newValue;
                cout << "Enter the value to insert: ";
                cin >> newValue;
                bst.insert(newValue);
                cout << "Tree after insertion: ";
                bst.printTree();
                break;
            }
            case 2: {
                int longestPath = bst.longestPathFromRoot();
                cout << "Longest path from root: " << longestPath << endl;
                break;
            }
            case 3: {
                int minValue = bst.findMin();
                cout << "Minimum value in the tree: " << minValue << endl;
                break;
            }
            case 4: {
                bst.swapChildren();
                cout << "Tree after swapping left and right children: ";
                bst.printTree();
                break;
            }
            case 5: {
                int searchValue;
                cout << "Enter the value to search: ";
                cin >> searchValue;
                if (bst.search(searchValue)) {
                    cout << searchValue << " found in the tree." << endl;
                } else {
                    cout << searchValue << " not found in the tree." << endl;
                }
                break;
            }
            case 6:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}





#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int key) : val(key), left(nullptr), right(nullptr) {}
};

class BST {
public:
    TreeNode* root;

    BST() : root(nullptr) {}

    TreeNode* insert(TreeNode* root, int key) {
        if (root == nullptr) {
            return new TreeNode(key);
        } else {
            if (key < root->val) {
                root->left = insert(root->left, key);
            } else {
                root->right = insert(root->right, key);
            }
            return root;
        }
    }

    void inorderTraversal(TreeNode* root) {
        if (root != nullptr) {
            inorderTraversal(root->left);
            cout << root->val << " ";
            inorderTraversal(root->right);
        }
    }

    void insertEmployeeIDs(vector<int>& employeeIDs) {
        for (int id : employeeIDs) {
            root = insert(root, id);
        }
    }
};

int main() {
    BST bst;
    vector<int> employeeIDs = {101, 204, 305, 402, 503, 609, 701};
    bst.insertEmployeeIDs(employeeIDs);

    cout << "Inorder Traversal of BST: ";
    bst.inorderTraversal(bst.root);
    cout << endl;

    return 0;
}

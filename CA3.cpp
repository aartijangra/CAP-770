// create a BST of 10 integer elements find and print sum of digit of each element in BST

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

    int sumOfDigits(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    void sumOfDigitsBST(TreeNode* root) {
        if (root != nullptr) {
            sumOfDigitsBST(root->left);
            cout << sumOfDigits(root->val) << " ";
            sumOfDigitsBST(root->right);
        }
    }
};

int main() {
    BST bst;
    vector<int> employeeIDs = {101, 204, 305, 402, 503, 609, 701, 123, 456, 789};
    bst.insertEmployeeIDs(employeeIDs);

    cout << "Inorder Traversal of BST: ";
    bst.inorderTraversal(bst.root);
    cout << endl;

    cout << "Sum of digits of each element in BST: ";
    bst.sumOfDigitsBST(bst.root);
    cout << endl;

    return 0;
}

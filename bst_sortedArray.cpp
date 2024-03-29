//binary search tree when the array is sorted
// 1. find the middle element of the array and make it the root
// 2. Recursively do the same for the left half and right half
// 3. The middle element of the left half will be the left child of the root
// 4. The middle element of the right half will be the right child of the root
// 5. Repeat the above steps for the left half and right half
// 6. The base case will be when the array is empty
// 7. The time complexity of this approach is O(n) where n is the number of elements in the array
// 8. The space complexity of this approach is O(n) where n is the number of elements in the array
// 9. This approach is better than the previous approach as it does not require any extra space
// 10. This approach is also better than the previous approach as it does not require any extra space

// Convert an sorted array to binary search tree
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTUtil(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* sortedArrayToBSTUtil(vector<int>& nums, int start, int end) {
        if (start > end)
            return nullptr;

        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBSTUtil(nums, start, mid - 1);
        root->right = sortedArrayToBSTUtil(nums, mid + 1, end);
        return root;
    }
};

void inorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->val << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    BST bst;
    TreeNode* root = bst.sortedArrayToBST(nums);

    cout << "Inorder Traversal of BST: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}

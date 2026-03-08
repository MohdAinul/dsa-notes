/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    // do bst to that we get sorted array
    void inorder(TreeNode* root, vector<int>& arr) {
        if (root == nullptr)
            return;
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
    // now built a bst using inorder(sorted array)
    TreeNode* builtBst(vector<int>& arr,int start, int end) {
        if (start > end) {
            return nullptr;
        }
        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = builtBst(arr, start, mid - 1);
        root->right = builtBst(arr, mid + 1, end);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inorder(root, arr);

        return builtBst(arr, 0, arr.size() - 1);
    }
};
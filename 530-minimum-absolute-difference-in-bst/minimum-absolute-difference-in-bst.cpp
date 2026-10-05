/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int min_diff = INT_MAX;
    int prev = -1; // -1 represents no previous node seen yet

    void inorder(TreeNode* node) {
        if (node == nullptr) return;

        // 1. Traverse Left Subtree
        inorder(node->left);

        // 2. Process Current Node
        if (prev != -1) {
            min_diff = std::min(min_diff, node->val - prev);
        }
        prev = node->val; // Update previous node value

        // 3. Traverse Right Subtree
        inorder(node->right);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return min_diff;
    }
};
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
    void dfs(TreeNode* root, TreeNode*& prev, TreeNode*& first, TreeNode*& second){

        if (root == nullptr){
            return;
        }

        dfs(root->left, prev, first, second);

        if (prev != nullptr && root->val < prev->val){
            if (first == nullptr){
                first = prev;
            }
            second = root;
        }

        prev = root;
        dfs(root->right, prev, first, second);
    }
public:
    void recoverTree(TreeNode* root) {
        /*
            inorder traversal 
            first 
            sec 
            prev

            keep track of prev until current is < prev 
            if it is < prev, first = prev, sec = current 
            swap first and sec 

        */

        TreeNode* first {nullptr};
        TreeNode* second {nullptr};
        TreeNode* prev {nullptr};

        dfs(root, prev, first, second);
        std::swap(first->val, second->val);
    }
};
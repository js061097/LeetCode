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
public:
    int sumRootToLeaf(TreeNode* root) {
        if(!root->left && !root->right)
            return root->val;
        int sum = 0;
        
        dfs_sum(root,sum,0);
        return sum;
    }
    void dfs_sum(TreeNode* root, int& sum, int curr){
        curr = (curr<<1) + root->val;
        if(!root->left && !root->right){
             sum = sum + curr;
            return;
        }
        
        if(!root->left){
            dfs_sum(root->right,sum,curr);
        }
        else if(!root->right){
            dfs_sum(root->left,sum,curr);
        }
        else{
            dfs_sum(root->left,sum,curr);
            dfs_sum(root->right,sum,curr);
        }
        
    }
};


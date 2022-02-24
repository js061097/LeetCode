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
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return root;
        stack<TreeNode*> stk;
        stk.push(root);
        TreeNode* curr = root;
        TreeNode* swap1;
        TreeNode* swap2;
        while(!stk.empty()){
            curr = stk.top();
            swap1 = curr->left;
            swap2 = curr->right;
            curr->left = swap2;
            curr->right = swap1;
            stk.pop();
            if(curr->left)
                stk.push(curr->left);
            if(curr->right) 
                stk.push(curr->right);
        }
        return root;
        
    }
};

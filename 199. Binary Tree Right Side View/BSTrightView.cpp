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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
        
        queue<TreeNode*> Q;
        Q.push(root);
        
        while(!Q.empty()){
            int n = Q.size();
            for(int i=0;i<n;i++){
                TreeNode* curr = Q.front();
                Q.pop();
                if(i==0)
                    res.push_back(curr->val);
                if(curr->right)
                    Q.push(curr->right);
                if(curr->left)
                    Q.push(curr->left);
            }
        }
        return res;
    }
};

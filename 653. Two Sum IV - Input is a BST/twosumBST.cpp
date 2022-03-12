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
    bool findTarget(TreeNode* root, int k) {
        if(!root->left && !root->right)
            return false;
        
        map<int,TreeNode*> bstmap;
        
        queue<TreeNode*> Q;
        Q.push(root);
        
        while(!Q.empty()){
            int n = Q.size();
            
            for(int i=0;i<n;i++){
                TreeNode* curr = Q.front();
                if(bstmap.find(k - curr->val)!=bstmap.end())
                    return true;
                bstmap[curr->val] = curr;
                Q.pop();
                if(curr->left)
                    Q.push(curr->left);
                if(curr->right)
                    Q.push(curr->right);
            }
        }
        return false;
    }
};

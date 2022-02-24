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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        queue<TreeNode*> Q;
        TreeNode* curr;
        
        Q.push(root);
        
        while(!Q.empty()){    
            vector<int> sub;
            int n=Q.size();
            for(int i=0;i<n;i++){
                curr = Q.front();
                Q.pop();
                sub.push_back(curr->val);
                if(curr->left)
                    Q.push(curr->left);
                if(curr->right)
                    Q.push(curr->right);
            }
            ans.push_back(sub);
        }
        
        return ans;
    }
};

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
            return true;
        if(!p || !q )
            return false;
        queue<TreeNode*> Q1,Q2;
        Q1.push(p);
        Q2.push(q);
        TreeNode* curr1, *curr2;
        while(!Q1.empty() || !Q2.empty()){
            curr1 = Q1.front();
            curr2 = Q2.front();
            
            cout<<curr1->val<<" "<<curr2->val<<endl;
            if(curr1->val!=curr2->val)
                return false;
            Q1.pop();
            Q2.pop();
            if(curr1->left && curr2->left)
            {
                 Q1.push(curr1->left);
                 Q2.push(curr2->left);
            }  
            if((!curr1->left && curr2->left) || (curr1->left && !curr2->left))
                return false;
            if(curr1->right && curr2->right)
            {   
                Q1.push(curr1->right);
                Q2.push(curr2->right);
            }
            if((!curr1->right && curr2->right) || (curr1->right && !curr2->right))
                return false;
        }
        return true;
    }
    
};

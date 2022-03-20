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
    int kthSmallest(TreeNode* root, int k) {
        //Return kth element while doing an inorder traversal
        vector<int> nodes;
        inorder(root,nodes);
        return nodes[k-1];
    }
    void inorder(TreeNode* root,vector<int> &nodes){
        if(root->left){
            inorder(root->left,nodes);
        }
        nodes.push_back(root->val);
        if(root->right){
            inorder(root->right,nodes);
        }
        
    }
};

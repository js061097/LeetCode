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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res,left,bottom,right;
        res.push_back(root->val);
        pLeft(root->left,left);
        pBottom(root->left,bottom);
        pBottom(root->right,bottom);
        pRight(root->right,right);
        
        res.insert(res.end(),left.begin(),left.end());
        res.insert(res.end(),bottom.begin(),bottom.end());
        res.insert(res.end(),right.begin(),right.end());
        return res;
    }
    void pLeft(TreeNode* root,vector<int> &left){
        if(root){
            if(!root->left && !root->right)
                return;
            else if(root->left){
                left.push_back(root->val);
                pLeft(root->left,left);
            }
            else if(root->right){
                left.push_back(root->val);
                pLeft(root->right,left);
            }  
        }
    }
    void pBottom(TreeNode* root, vector<int> &bottom){
        if(root){
            if(!root->left && !root->right){
                bottom.push_back(root->val);
                return;
            }
            if(root->left){
                pBottom(root->left,bottom);
            }
            if(root->right){
                pBottom(root->right,bottom);
            }
        }
    }
    void pRight(TreeNode* root,vector<int> &right){
        if(root){
            if(!root->left && !root->right)
                return;
            else if(root->right){
                right.emplace(right.begin(),root->val);
                pRight(root->right,right);
            }
            else if(root->left){
                right.emplace(right.begin(),root->val);
                pRight(root->left,right);
            }  
        }
    }
};

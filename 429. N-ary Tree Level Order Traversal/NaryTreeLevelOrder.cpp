/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        queue<Node*> Q;
        Q.push(root);
        
        while(!Q.empty()){
            int qs = Q.size();
            vector<int> level;
            while(qs--!=0){
                Node* curr = Q.front();
                level.push_back(curr->val);
                Q.pop();
                for(auto it: curr->children){
                    Q.push(it);
                } 
            }
            res.push_back(level);
        }
        return res;
    }
};

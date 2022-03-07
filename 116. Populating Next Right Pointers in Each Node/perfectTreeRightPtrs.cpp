/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return root;
        queue<Node*> Q;
        Q.push(root->left);
        Q.push(root->right);

        int flag = 1;
        while(!Q.empty()){
            int n = Q.size();
            for(int i=0;i<n-1;i++){
                Node* curr = Q.front();
                Q.pop();
                if(!curr){
                    flag = 2;
                    break;
                }
                Q.push(curr->left);
                Q.push(curr->right);
                curr->next = Q.front();
            }
            if(flag==2)
                break;
            Q.push(Q.front()->left);
            Q.push(Q.front()->right);
            Q.pop();
        }
        return root;
    }
    
};

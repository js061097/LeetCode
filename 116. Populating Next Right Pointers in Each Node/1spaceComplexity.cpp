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
        
        Node* leftmost = root;
        while(leftmost->left!=nullptr){
            
            Node* head = leftmost;
            
            while(head!=nullptr){
                head->left->next = head->right;
                
                if(head->next!=nullptr){
                    head->right->next = head->next->left;
                }
                
                head = head->next;
            }
            
            leftmost = leftmost->left;
        }
        
        return root;
    }
    
};

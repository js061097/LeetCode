/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    map<Node*,Node*> nodemap;
public:
    Node* cloneGraph(Node* node) {
        if(!node)
            return nullptr;
        
        if(nodemap.find(node)==nodemap.end())
        {
            nodemap[node] = new Node(node->val);
            
            for(auto it: node->neighbors)
                nodemap[node]->neighbors.push_back(cloneGraph(it));
        }
        
    
        return nodemap[node];
        
    }
};

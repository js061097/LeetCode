class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> subres;
        int n = graph.size();
        subres.push_back(0);
        backtrack(0,n-1,graph,subres,res);
       
        return res;
    }
    void backtrack(int source,int dest,vector<vector<int>> graph,vector<int> subres,vector<vector<int>> &res){
        if(source == dest){
            res.push_back(subres);
            return;
        }
        for(int i: graph[source]){
            subres.push_back(i);
            backtrack(i,dest,graph,subres,res);
            subres.pop_back();
        }
        
    }
};


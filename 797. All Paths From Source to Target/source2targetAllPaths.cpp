class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        stack<int> stk;
        vector<int> subres;
        subres.push_back(0);
        backtrack(graph,res,subres,0,graph.size()-1);
        return res;
    }
void backtrack(vector<vector<int>>& graph, vector<vector<int>>& res, vector<int> pass, int start,int end){
    
    if(start == end){
        res.push_back(pass);
        return;
    }
    if(graph[start].size() == 0)
        return;
    for(int i=0;i<graph[start].size();i++){
        pass.push_back(graph[start][i]);
        backtrack(graph,res,pass,graph[start][i],end);
        pass.pop_back();
    }
}
    
};

/*
Backtracking

recursive calls to nodes present in adjList
push new elements into a vector<int>
till destination is reached 
    if reached push the element and return/add the vector to solution

*/

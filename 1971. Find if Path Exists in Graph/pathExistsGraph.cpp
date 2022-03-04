class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adjList(n);
        for(vector<int> edge: edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        stack<int> stk;
        vector<int> visited(n,0);
        stk.push(source);
        while(!stk.empty()){
            int curr = stk.top();
            if(curr == destination)
                return true;
            visited[curr] = 1;
            stk.pop();
            for(int i=0;i<adjList[curr].size();i++){
                if(!visited[adjList[curr][i]])
                    stk.push(adjList[curr][i]);
            }
            
        }
        return false;
        
    }
};

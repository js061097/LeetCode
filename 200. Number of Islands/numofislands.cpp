class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> visited(grid.size(),vector<int> (grid[0].size()));
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    dfs(grid,visited,i,j);
                    count++;
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<char>>& grid,vector<vector<int>>& visited,int m,int n){
        if(m<grid.size() && n<grid[0].size() && m>=0 && n>=0){
            if(grid[m][n]=='1' && !visited[m][n]){
                visited[m][n] = 1;
                dfs(grid,visited,m+1,n);
                dfs(grid,visited,m,n+1);
                dfs(grid,visited,m-1,n);
                dfs(grid,visited,m,n-1);
            }
        }
    }
    
};



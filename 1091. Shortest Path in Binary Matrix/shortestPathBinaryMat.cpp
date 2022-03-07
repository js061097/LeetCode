class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0)
            return -1;
        vector<vector<int>> directions = {{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0}};
        
        queue<vector<int>> Q;
        
        Q.push({0,0});
        int count = 1;
        while(!Q.empty()){
            int qs = Q.size();
            for(int i=0;i<qs;i++){
            vector<int> curr = Q.front();
            if(curr[0]==n-1 && curr[1] == n-1)
                return count;
            Q.pop();
            for(auto dir: directions){
                if(curr[0] + dir[0]>=0 && curr[0] + dir[0]<n && curr[1] + dir[1]>=0 && curr[1] + dir[1]<n)
                    if(grid[curr[0] + dir[0]][curr[1] + dir[1]] == 0)
                    {Q.push({curr[0] + dir[0],curr[1] + dir[1]});
                    grid[curr[0] + dir[0]][curr[1] + dir[1]] = 1;}
            }
            }
            
            count++;
        }
        return -1;
    }

    
};

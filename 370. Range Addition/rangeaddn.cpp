class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> ans(length,0);
        int start,end,update = 0;
        for(auto it: updates){
            start = it[0];
            end = it[1];
            update = it[2];
            
            ans[start]+=update;
            if(end+1<length)
                ans[end+1]-=update;        
        }
        
        for(int i=1;i<length;i++){
            ans[i]+=ans[i-1];
        }
        return ans;
    }
};

/*
 0 0 0 0 0 
 0 2    -2
 0 2 3  -2
-2 2 3 2-2 
 
 res[i] += res[i-1]
 
 -2 0 3 5 3
 
*/

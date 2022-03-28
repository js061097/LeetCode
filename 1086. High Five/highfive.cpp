class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b){
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    }
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        vector<vector<int>> res;
        int n = items.size();
        
        sort(items.begin(),items.end(),cmp);
        map<int,int> avgmap;
        
        for(int i=0;i<n;i++){
            int sum=0;
            if(avgmap.find(items[i][0])==avgmap.end()){
                for(int j=i;j<i+5;j++){
                    sum+=items[j][1];
                }
                avgmap[items[i][0]] = sum/5;
            }
        }
        for(auto it=avgmap.begin();it!=avgmap.end();it++){
            res.push_back({it->first,it->second});
        }
        return res;
    }
};

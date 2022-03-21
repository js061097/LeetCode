class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subres;
        int n = nums.size();
        recur(0,n,nums,subres,res);
        return res;
    }
    void recur(int pos, int n, vector<int> nums, vector<int> subres,vector<vector<int>>& res){
        if(pos==n){
            res.push_back(subres);
            return;
        }
        for(int i=0;i<nums.size();i++){
            int temp = nums[i];
            subres.push_back(nums[i]);
            nums.erase(nums.begin()+i);
            recur(pos+1,n,nums,subres,res);
            nums.emplace(nums.begin()+i,temp);
            subres.pop_back();
        }
    }
};


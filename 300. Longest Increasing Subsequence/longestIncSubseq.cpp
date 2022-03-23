class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return 1;
        }
        int res = 1;
        vector<int> LIS(n);
        LIS[n-1] = 1;
        for(int i=n-2;i>=0;i--){
            int max = 0;
            for(int j=i+1;j<n;j++){
                if(nums[i]<nums[j]){
                    if(LIS[j] > max)
                        max = LIS[j];
                }
            } 
            LIS[i] = max + 1;
            if(LIS[i]>res)
                res = LIS[i];
        }
        return res;
        
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      map<int,int> twosum;
      vector<int> ans;
      int diff;
      for(int i=0;i<nums.size();i++){
          diff = target - nums[i];
          if(twosum.find(diff)!=twosum.end()){
              ans.push_back(twosum.find(diff)->second);
              ans.push_back(i);
              return ans;
          }
          else{
              twosum[nums[i]] = i;
          }
      }
        return ans;
    }

};


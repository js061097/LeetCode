class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        if(start==end){
            return (target==nums[start])?0:-1;
        }
        while(start!=end){
            int mid = (start+end)/2;
            if(target>nums[mid])
                start = mid+1;
            else if(target<nums[mid])
                end = mid-1;
            else
                return mid;
            if(start<0 || end<0)
                return -1;
        }
        return (nums[start]==target)? start:-1;
    }
};

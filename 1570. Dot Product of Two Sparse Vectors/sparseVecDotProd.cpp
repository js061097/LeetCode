class SparseVector {
public:
    map<int,int> nonsparse;
    SparseVector(vector<int> &nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0)
                nonsparse[i] = nums[i];
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int res=0;
        for(auto i:nonsparse){
            if(vec.nonsparse.find(i.first)!=vec.nonsparse.end())
                res+=vec.nonsparse[i.first]*nonsparse[i.first];
        }
        return res;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);

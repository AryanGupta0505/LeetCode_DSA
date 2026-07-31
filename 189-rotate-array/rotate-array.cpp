class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // vector<int> nums1(nums.size());
        // for(int i=0;i<nums.size();i++){
        //     nums1[(i+k)%nums.size()]=nums[i];
        // }
        // nums=nums1;
        //in-place solution
        int n = nums.size();
        k %= n;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
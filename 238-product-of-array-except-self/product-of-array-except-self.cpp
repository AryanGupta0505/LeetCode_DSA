class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        // vector<int> prefix(n,1);
        // vector<int> suffix(n,1);
        vector<int> ans(n,1);
        // for(int i=1;i<n;i++){
        //     prefix[i]=prefix[i-1]*nums[i-1];
        // }
        // for(int i=n-2;i>=0;i--){
        //     suffix[i]=suffix[i+1]*nums[i+1];
        // }
        // for(int i=0;i<n;i++){
        //     ans[i]=prefix[i]*suffix[i];
        // }
        for(int i=1;i<n;i++){
            ans[i]=ans[i-1]*nums[i-1];
        }
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }
        return ans;
    }
};
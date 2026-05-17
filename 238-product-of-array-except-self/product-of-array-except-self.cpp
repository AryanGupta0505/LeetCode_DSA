class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int product=1;
        for(int i=0;i<n;i++){
            product=product*nums[i];
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                int p=1;
                for(int j=0;j<n;j++){
                    if(j==i) continue;
                    p=p*nums[j];
                }
                ans[i]=p;
                continue;
            }
            ans[i]=product/nums[i];
        }
        return ans;
    }
};
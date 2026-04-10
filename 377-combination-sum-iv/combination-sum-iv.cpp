class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long> dp(target+1,0);
        dp[0]=1;
        for(int i=1;i<=target;i++){
            for(int j=0;j<nums.size();j++){
                if(i-nums[j]>=0){
                    if (dp[i] > LLONG_MAX - dp[i - nums[j]]) {
                        dp[i] = LLONG_MAX; // cap it
                    } else {
                        dp[i] += dp[i - nums[j]];
                    }
                }
            }
        }
        return (int)dp[target];
    }
};
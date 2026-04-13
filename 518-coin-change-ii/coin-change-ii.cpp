class Solution {
public:
    // int solveMem(vector<int>& coins,int i,int x,vector<vector<int>>&dp){
    //     if (x == 0) return 1;
    //     if (i >= coins.size() || x < 0) return 0;
    //     if (dp[i][x] != -1) return dp[i][x];
    //     int in=solveMem(coins,i,x-coins[i],dp);
    //     int ex=solveMem(coins,i+1,x,dp);
    //     dp[i][x]=in+ex;
    //     return dp[i][x];
    // }
    // int solveTab(vector<int>&coins,int x){
    //     int n=coins.size();
    //     vector<vector<long long>> dp(n+1, vector<long long>(x + 1, 0));
    //     for(int j=0;j<=n;j++){
    //         dp[j][0]=1;
    //     }
    //     for(int i=n-1;i>=0;i--){
    //         for(int k=0;k<=x;k++){
    //             long long in=0;
    //             if(k-coins[i]>=0)
    //                 in=dp[i][k-coins[i]];
    //             long long ex=dp[i+1][k];
    //             // dp[i][k]=in+ex;
    //             dp[i][k] = min((long long)INT_MAX, in + ex);
    //         }
    //     }
    //     return (int)dp[0][x];
    // }

    // int change(int amount, vector<int>& coins) {
    //     // vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
    //     // int ans=solveMem(coins,0,amount,dp);
    //     // return ans;
    //     return solveTab(coins,amount);
    // }
    int change(int amount, vector<int>& coins) {
        vector<long long> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (int k = coin; k <= amount; k++) {
                dp[k]=min((long long)INT_MAX,dp[k]+ dp[k - coin]);
            }
        }

        return (int)dp[amount];
    }
};
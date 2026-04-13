class Solution {
public:
    int solveMem(vector<int>& coins,int i,int x,vector<vector<int>>&dp){
        if (x == 0) return 1;
        if (i >= coins.size() || x < 0) return 0;
        if (dp[i][x] != -1) return dp[i][x];
        int in=solveMem(coins,i,x-coins[i],dp);
        int ex=solveMem(coins,i+1,x,dp);
        dp[i][x]=in+ex;
        return dp[i][x];
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        int ans=solveMem(coins,0,amount,dp);
        return ans;
    }
};
class Solution {
public:
    int solveMem(int n,vector<int>& days,vector<int>& costs,int index,vector<int>&dp){
        if(index>=n) return 0;
        if(dp[index]!=-1) return dp[index];
        int op1=costs[0]+solveMem(n,days,costs,index+1,dp);
        int i;
        for(i=index;i<n&&days[i]<days[index]+7;i++);
        int op2=costs[1]+solveMem(n,days,costs,i,dp);
        for(i=index;i<n&&days[i]<days[index]+30;i++);
        int op3=costs[2]+solveMem(n,days,costs,i,dp);
        dp[index]=min(op1,min(op2,op3));
        return dp[index];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int>dp(n+1,-1);
        return solveMem(n,days,costs,0,dp);
    }
};
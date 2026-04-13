class Solution {
public:
    // int solveMem(int n,vector<int>& days,vector<int>& costs,int index,vector<int>&dp){
    //     if(index>=n) return 0;
    //     if(dp[index]!=-1) return dp[index];
    //     int op1=costs[0]+solveMem(n,days,costs,index+1,dp);
    //     int i;
    //     for(i=index;i<n&&days[i]<days[index]+7;i++);
    //     int op2=costs[1]+solveMem(n,days,costs,i,dp);
    //     for(i=index;i<n&&days[i]<days[index]+30;i++);
    //     int op3=costs[2]+solveMem(n,days,costs,i,dp);
    //     dp[index]=min(op1,min(op2,op3));
    //     return dp[index];
    // }
    // int solveTab(int n,vector<int>&days,vector<int>&costs){
    //     vector<int>dp(n+1,INT_MAX);
    //     dp[n]=0;
    //     for(int k=n-1;k>=0;k--){
    //         int op1=costs[0]+dp[k+1];
    //         int i;
    //         for(i=k;i<n&&days[i]<days[k]+7;i++);
    //         int op2=costs[1]+dp[i];
    //         for(i=k;i<n&&days[i]<days[k]+30;i++);
    //         int op3=costs[2]+dp[i];
    //         dp[k]=min(op1,min(op2,op3));
    //     }
    //     return dp[0];
    // }
    int solveSpace(int n,vector<int>&days,vector<int>&costs){
        int ans=0;
        queue<pair<int,int>>month;
        queue<pair<int,int>>week;
        for(int day:days){
            while(!month.empty()&&month.front().first+30<=day)
                month.pop();
            while(!week.empty()&&week.front().first+7<=day)
                week.pop();
            week.push({day,ans+costs[1]});
            month.push({day,ans+costs[2]});
            ans=min(ans+costs[0],min(week.front().second,month.front().second));
        }
        return ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        // vector<int>dp(n+1,-1);
        // return solveMem(n,days,costs,0,dp);
        // return solveTab(n,days,costs);
        return solveSpace(n,days,costs);
    }
};
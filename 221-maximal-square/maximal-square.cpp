class Solution {
public:
    int solveMem(vector<vector<char>>& matrix,int i,int j,int &maxi,vector<vector<int>>& dp){
        if(i>=matrix.size()||j>=matrix[0].size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int right=solveMem(matrix,i,j+1,maxi,dp);
        int diagonal=solveMem(matrix,i+1,j+1,maxi,dp);
        int down=solveMem(matrix,i+1,j,maxi,dp);
        if(matrix[i][j]=='1'){
            dp[i][j]=1+min(right,min(diagonal,down));
            maxi=max(maxi,dp[i][j]);
        }
        else{
            dp[i][j]=0;
        }
        return dp[i][j];
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi=0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        solveMem(matrix,0,0,maxi,dp);
        return maxi*maxi;
    }
};
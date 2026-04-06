class Solution {
public:
    void solve(vector<vector<int>>& ans,vector<int> output,int index,int n,int k){
        if(output.size()==k){
            ans.push_back(output);
            return;
        }
        for(int i=index;i<=n;i++){
            output.push_back(i);
            solve(ans,output,i+1,n,k);
            output.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        int index=1;
        vector<int> output;
        solve(ans,output,index,n,k);
        return ans;
    }
};
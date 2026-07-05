class Solution {
public:
    void solve(int k, int n,vector<int> way,vector<vector<int>>& ans,int index){
        if(k==0&&n==0){
            ans.push_back(way);
            return;
        }
        if((k==0&&n!=0)||(k!=0&&n==0)) return;
        for(int i=index;i<=9;i++){
            way.push_back(i);
            solve(k-1,n-i,way,ans,i+1);
            way.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> way;
        vector<vector<int>> ans;
        solve(k,n,way,ans,1);
        return ans;
    }
};
class Solution {
public:
    void solve(vector<int>& candidates, int target,vector<vector<int>>& ans,vector<int> way,int index){
        if(target<0) return;
        if(target==0){
            ans.push_back(way);
        }
        for(int i=index;i<candidates.size();i++){
            if(candidates[i]<=target){
                way.push_back(candidates[i]);
                solve(candidates,target-candidates[i],ans,way,i);
                way.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> way;
        solve(candidates,target,ans,way,0);
        return ans;
    }
};
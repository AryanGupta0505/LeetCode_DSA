class Solution {
public:
    void solve(vector<int>& candidates, int target,vector<vector<int>>& ans,vector<int> way,int index){
        if(target<0) return;
        if(target==0){
            ans.push_back(way);
        }
        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1])
                continue;
            if(candidates[i]>target) break;
            way.push_back(candidates[i]);
            solve(candidates,target-candidates[i],ans,way,i+1);
            way.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> way;
        solve(candidates,target,ans,way,0);
        return ans;
    }
};
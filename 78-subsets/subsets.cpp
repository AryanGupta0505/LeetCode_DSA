class Solution {
public:
    void solve(vector<int>& nums,vector<int> op,vector<vector<int>>&ans,int index){
        if(index>=nums.size()){
            if(op.size()>=0){
                ans.push_back(op);
                return;
            }
        }
        solve(nums,op,ans,index+1);
        int element=nums[index];
        op.push_back(element);
        solve(nums,op,ans,index+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(nums,output,ans,0);
        return ans;
    }
};
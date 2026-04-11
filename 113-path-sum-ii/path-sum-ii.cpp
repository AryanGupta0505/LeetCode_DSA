/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root,int targetSum,int sum,vector<int>&path , vector<vector<int>>&res){
        if(root==NULL) return;
        sum+=root->val;
        path.push_back(root->val);
        if(root->left==NULL && root->right==NULL &&sum==targetSum){
            res.push_back(path);
        }
        solve(root->left,targetSum,sum,path,res);
        solve(root->right,targetSum,sum,path,res);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        solve(root,targetSum,0,path,ans);
        return ans;
    }
};
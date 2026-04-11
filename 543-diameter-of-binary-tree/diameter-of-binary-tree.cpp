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
    pair<int,int> solve(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }
        pair<int,int> left=solve(root->left);
        pair<int,int> right=solve(root->right);
        int leftAns=left.first;
        int rightAns=right.first;
        int combo=left.second+right.second+1;
        pair<int,int> ans;
        ans.first=max(leftAns,max(rightAns,combo));
        ans.second=max(left.second,right.second)+1;
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return solve(root).first-1;
    }
};
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
    // void inorder(TreeNode* root,vector<int>&in){
    //     if(root==NULL){
    //         return;
    //     }
    //     inorder(root->left,in);
    //     in.push_back(root->val);
    //     inorder(root->right,in);
    // }
    void inorder(TreeNode* root,vector<int>&in){
        stack<TreeNode*>s;
        TreeNode* curr=root;
        while(curr!=NULL||!s.empty()){
            while(curr!=NULL){
                s.push(curr);
                curr=curr->left;
            }
            curr=s.top();
            s.pop();
            in.push_back(curr->val);
            curr=curr->right;
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int> ans;
       inorder(root,ans);
       return ans;
    }
};
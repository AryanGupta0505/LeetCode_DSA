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
    void levelOrder(TreeNode* root, vector<vector<int>>&level){
        if(root==NULL) return;
        queue<TreeNode*> q;
        q.push(root);
        stack<vector<int>> s;
        while(!q.empty()){
            vector<int>v;
            int n=q.size();
            while(n>0){
                v.push_back(q.front()->val);
                if(q.front()->left){
                    q.push(q.front()->left);
                }
                if(q.front()->right){
                    q.push(q.front()->right);
                }
                q.pop();
                n--;
            }
            // level.push_back(v);
            s.push(v);
        }
        while(!s.empty()){
            level.push_back(s.top());
            s.pop();
        }
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        levelOrder(root,ans);
        // reverse(ans.begin(),ans.end());
        return ans;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nodes;
        ListNode* temp=head;
        while(temp!=NULL){
            nodes.push_back(temp->val);
            temp=temp->next;
        }
        stack<int>s;
        // s.push(-1);
        vector<int> ans(nodes.size(),0);
        for(int i=nodes.size()-1;i>=0;i--){
            int curr=nodes[i];
            while(!s.empty()&&s.top()<=curr){
                s.pop();
            }
            ans[i] = s.empty() ? 0 : s.top();
            s.push(curr);
        }
        return ans;
    }
};
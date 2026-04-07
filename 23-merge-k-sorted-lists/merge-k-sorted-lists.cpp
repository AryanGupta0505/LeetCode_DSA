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
    ListNode* merge(ListNode* first,ListNode* second){
        if(first==NULL){
            return second;
        }
        if(second==NULL){
            return first;
        }
        ListNode* ans=new ListNode(-1);
        ListNode* temp=ans;
        while(first!=NULL&&second!=NULL){
            if(first->val<second->val){
                temp->next=first;
                temp=first;
                first=first->next;
            }
            else{
                temp->next=second;
                temp=second;
                second=second->next;
            }
        }
        while(first!=NULL){
            temp->next=first;
            temp=first;
            first=first->next;
        }
        while(second!=NULL){
            temp->next=second;
            temp=second;
            second=second->next;
        }
        ans=ans->next;
        return ans;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = NULL;
        for (int i = 0; i < lists.size(); i++) {
            head = merge(head, lists[i]);
        }
        return head;
    }
};
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
    ListNode* reverseList(ListNode* head,int start,int end) {
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* forward=NULL;
        while(start<=end){
            // cout<<curr->val<<" "<<start<<endl;
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            start++;
        }
        head->next=curr;
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL||head->next==NULL) return head;
        if(left==right) return head;
        ListNode* temp=NULL;
        ListNode* start=head;
        int cnt=1;
        while(cnt<left){
            temp=start;
            start=start->next;
            cnt++;
        }
        if(temp==NULL) return reverseList(start,cnt,right);
        else temp->next=reverseList(start,cnt,right);
        return head;
    }
};
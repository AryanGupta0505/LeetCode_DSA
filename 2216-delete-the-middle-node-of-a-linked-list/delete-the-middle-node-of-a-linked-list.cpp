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
    int getLength(ListNode* head){
        ListNode* temp=head;
        int len=0;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        return len;
    }
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
         if(head->next == NULL){
            // delete head;
            return NULL;
        }
        int length=getLength(head);
        int mid=length/2 +1;
        ListNode* temp=head;
        int i=0;
        while(temp!=NULL && i<mid-2){
            temp=temp->next;
            i++;
        }
        if(temp!=NULL && temp->next!=NULL) temp->next=temp->next->next;
        return head;
    }
};
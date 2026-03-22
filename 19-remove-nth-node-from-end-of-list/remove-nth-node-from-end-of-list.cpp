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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return NULL;
        int length=getLength(head);
        if (n == length) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        ListNode* curr=head;
        int i=length-n;
        while(i-1>0){
            curr=curr->next;
            i--;
        }
        ListNode* link=NULL;
        if(curr->next!=NULL) link=curr->next->next;
        ListNode* nodeToDelete=curr->next;
        curr->next=link;
        delete(nodeToDelete);
        // cout<<curr->val;
        return head;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* first=headA;
        // ListNode* second=headB;
        while(first!=NULL){
            int element=first->val;
            ListNode* second=headB;
            while(second!=NULL){
                if(element==second->val&&first==second){
                    return second;
                    break;
                }
                second=second->next;
            }
            first=first->next;
        }
        return NULL;
    }
};
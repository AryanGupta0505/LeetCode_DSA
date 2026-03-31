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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* aNode=list1;
        ListNode* aNodePrev=list1;
        ListNode* bNode=list1;
        ListNode* bNodeNext=list1;
        ListNode* temp=list2;
        for(int i=1;i<a;i++){
            aNodePrev=aNodePrev->next;
        }
        for(int i=0;i<b;i++){
            bNode=bNode->next;
        }
        aNode=aNodePrev->next;
        bNodeNext=bNode->next;
        aNodePrev->next=list2;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=bNode->next;
        bNode->next=NULL;
        return list1;
    }
};
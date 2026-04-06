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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: Find length
        ListNode* temp = head;
        int len = 1;
        while (temp->next) {
            temp = temp->next;
            len++;
        }

        // Step 2: Normalize k
        k = k % len;
        if (k == 0) return head;

        // Step 3: Make circular
        temp->next = head;

        // Step 4: Find new tail
        int stepsToNewHead = len - k;
        ListNode* newTail = head;

        for (int i = 1; i < stepsToNewHead; i++) {
            newTail = newTail->next;
        }

        // Step 5: Break circle
        ListNode* newHead = newTail->next;
        newTail->next = NULL;

        return newHead;
    }
};
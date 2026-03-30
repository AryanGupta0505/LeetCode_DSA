/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertAtTail(Node* &head,Node* &tail,int val){
        Node* temp=new Node(val);
        if(head==NULL){
            head=temp;
            tail=temp;
            return;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
    }
    Node* copyRandomList(Node* head) {
        Node* cloneHead=NULL;
        Node* cloneTail=NULL;
        Node* temp=head;
        while(temp!=NULL){
            insertAtTail(cloneHead,cloneTail,temp->val);
            temp=temp->next;
        }
        Node* originalNode=head;
        Node* cloneNode=cloneHead;
        while(originalNode!=NULL && cloneNode!=NULL){
            Node* next=originalNode->next;
            originalNode->next=cloneNode;
            originalNode=next;
            next=cloneNode->next;
            cloneNode->next=originalNode;
            cloneNode=next;
        }
        temp=head;
        while(temp!=NULL){
            if(temp->next!=NULL){
                if(temp->random!=NULL){
                    temp->next->random=temp->random->next;
                }
                else{
                    temp->next->random=temp->random;
                }
            }
            temp=temp->next->next;
        }
        originalNode=head;
        cloneNode=cloneHead;
        while(originalNode!=NULL && cloneNode!=NULL){
            originalNode->next=cloneNode->next;
            originalNode=originalNode->next;
            if(originalNode!=NULL){
                cloneNode->next=originalNode->next;
            }
            cloneNode=cloneNode->next;
        }
        return cloneHead;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListListNode {
 *     int val;
 *     ListListNode *next;
 *     ListListNode() : val(0), next(nullptr) {}
 *     ListListNode(int x) : val(x), next(nullptr) {}
 *     ListListNode(int x, ListListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode* kReverse(ListNode* head, int k) {
    
    
    if(head==NULL){
        return NULL;
    }
      ListNode* temp = head;
        for (int i = 0; i < k; i++) {
            if (!temp) return head; 
            temp = temp->next;
        }
    ListNode *forward=NULL;
    ListNode* curr=head;
    ListNode*prev=NULL;
    int count=0;
         while(curr!=NULL && count !=k){
          forward=curr->next;
          curr->next=prev;
          prev=curr;
          curr=forward;
          count++;   
   }  
    if(forward!=NULL){
        head->next=kReverse(forward,k);
         
    }
      return prev; 
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        

        return kReverse(head,k);
    }
};
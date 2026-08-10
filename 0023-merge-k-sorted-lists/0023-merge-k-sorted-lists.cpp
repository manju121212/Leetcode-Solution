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

class compare{
   public:
  bool operator()(ListNode* d1,ListNode* d2){
    return d1->val > d2->val;
  }
};

class Solution {
 
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
         priority_queue <ListNode*, vector<ListNode*>, compare > pq;
        
        ListNode* head= new ListNode(-1);
        ListNode* tail=head;
        for(int i=0;i<lists.size();i++){
         
            if(lists[i]!=NULL){
                pq.push(lists[i]);
            }
        }
        
        while(!pq.empty()){
            
            ListNode* temp=pq.top();
            pq.pop();
            
            tail->next=temp;
            tail=temp;
            
            if(temp->next){
                pq.push(temp->next);
            }
        }
        
        return head->next;
    } 
};
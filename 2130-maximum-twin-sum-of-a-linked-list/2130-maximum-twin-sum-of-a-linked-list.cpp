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
    int pairSum(ListNode* head) {
         
         vector<int>result;

         while(head != NULL){
              result.push_back(head->val);
              head = head->next;
         }

         int size = result.size();
         int maxi = -1;
         for(int i = 0;i<size/2;i++){
                int curr = result[i] + result[size-1-i];
                maxi = max(maxi , curr);
         }

         return maxi;

    }
};
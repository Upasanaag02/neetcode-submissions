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
    void reorderList(ListNode* head) {
          ListNode* slow=head;
          ListNode* fast=head;
          while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
          }
          ListNode* newList=slow->next;
          slow->next = nullptr;
          ListNode* newNode;
          ListNode* prev=nullptr;
          while(newList!=nullptr){
              ListNode* newNode=newList->next;
              newList->next=prev;
              prev=newList;
              newList=newNode;
          }
          ListNode* first=head;
          ListNode* second=prev;
          while(second){
                ListNode* tmp1 = first->next;
                ListNode* tmp2 = second->next;

                first->next = second;
                second->next = tmp1;

                first = tmp1;
                second = tmp2;
        }
          
    }
};

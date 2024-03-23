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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* temp=head;

        while(fast && fast->next){
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }

        temp->next=NULL;

        ListNode* frwd=slow->next;
        ListNode* prev=NULL;

        while(slow){
            slow->next=prev;
            prev=slow;
            slow=frwd;
            if(frwd) frwd=frwd->next;
        }
        while(head){
            if(head->val==prev->val){
                head=head->next;
                prev=prev->next;
            }
            else return false;
        }
        return true;
    }
};
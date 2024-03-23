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
        //slow and fast pointer method
        //finding mid node to seperate list in 2 diff lists
        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* midNode=slow;
        ListNode* list2=midNode->next;
        midNode->next=NULL;

        ListNode* prev=NULL;

        //reverse second list

        while(list2){
            ListNode* forward=list2->next;
            list2->next=prev;
            prev=list2;
            list2=forward;
        }

        //merge 2 lists node1(a)->node2(a)->node1(b)->node2(b)

        ListNode* p2=prev;
        ListNode* p1=head;

        while(p2 && p1){
            ListNode* nextNode1=p1->next;
            ListNode* nextNode2=p2->next;
            p1->next=p2;
            p2->next=nextNode1;
            p1=nextNode1;
            p2=nextNode2;

        }
    }
};
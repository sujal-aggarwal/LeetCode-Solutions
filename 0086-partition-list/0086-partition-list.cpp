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
    ListNode* partition(ListNode* head, int x) {
        ListNode*new_head=new ListNode(0);
        ListNode*temp2=new_head;
        ListNode*temp=head;
        while(temp){
            if(temp->val<x){
                temp2->next=new ListNode(temp->val);
                temp2=temp2->next;
            }
            temp=temp->next;
        }
        temp=head;
        while(temp){
            if(temp->val>=x){
                temp2->next=new ListNode(temp->val);
                temp2=temp2->next;
            }
            temp=temp->next;
        }
        return new_head->next;
    }
};
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
        vector<int>arr;
        ListNode*temp=head;
        while(temp){
            if(temp->val<x)
                arr.push_back(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(temp){
            if(temp->val>=x)
                arr.push_back(temp->val);
            temp=temp->next;
        }
        ListNode*new_head=new ListNode(0);
        ListNode*temp2=new_head;
        for(auto i:arr){
            ListNode*temp=new ListNode(i);
            temp2->next=temp;
            temp2=temp2->next;
        }
        return new_head->next;
    }
};
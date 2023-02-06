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
    int length(ListNode*head)
    {
        ListNode*temp=head;
        int i=1;
        while(temp->next!=NULL){
            temp=temp->next;
            i++;
        }
        return i;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=length(head);
        if(n==len)
            return head->next;
        ListNode*temp=head;
        int i=1;
        ListNode*prev;
        while(i<len-n+1)
        {
            prev=temp;
            temp=temp->next;
            i++;
        }
        prev->next=temp->next;
        return head;
    }
};
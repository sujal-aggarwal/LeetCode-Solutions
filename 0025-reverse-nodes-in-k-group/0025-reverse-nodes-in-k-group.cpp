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
    bool length(ListNode*head,int k){
        if(!head)return false;
        ListNode*temp=head;
        int cnt=1;
        while(temp->next){
            temp=temp->next;
            cnt++;
            if(cnt>=k)return true;
        }
        return false;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL)return NULL;
        ListNode*temp=head;
        ListNode*prev=NULL;
        int cnt=0;
        if(!length(head,k))return head;
        while(cnt<k){
            ListNode*temp2=temp->next;
            temp->next=prev;
            prev=temp;
            temp=temp2;
            cnt++;
        }
        head->next=reverseKGroup(temp,k);
        return prev;
    }
};
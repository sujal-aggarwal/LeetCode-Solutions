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
    pair<ListNode*,ListNode*>reverse(ListNode*head){
        if(head->next){
            pair<ListNode*,ListNode*>rev=reverse(head->next);
            ListNode*start=rev.first;
            ListNode*end=rev.second;
            ListNode*temp=new ListNode(head->val);
            end->next=temp;
            return {start,temp};
        }
        ListNode*temp=new ListNode(head->val);
        return {temp,temp};
    }
    int length(ListNode*head){
        if(!head)return 0;
        return 1+length(head->next);
    }
    int pairSum(ListNode* head) {
        pair<ListNode*,ListNode*>p=reverse(head);
        int n=length(head);
        ListNode*rev=p.first;
        int ans=0;
        for(int i=0;i<n/2;i++){
            ans=max(ans,head->val+rev->val);
            rev=rev->next;
            head=head->next;
        }
        return ans;
    }
};
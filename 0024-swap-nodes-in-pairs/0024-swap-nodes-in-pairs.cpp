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
    ListNode* swapPairs(ListNode* head) {
        if((!head)||(!head->next))return head;
        ListNode*h=head;
        ListNode*n=h->next;
        ListNode*a=swapPairs(n->next);
        h->next=a;
        n->next=h;
        return n;
    }
};
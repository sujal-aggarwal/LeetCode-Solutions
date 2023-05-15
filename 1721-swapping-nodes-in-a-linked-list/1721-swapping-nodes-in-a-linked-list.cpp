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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode*temp1=head,*t=head,*temp2=head;
        int length=1;
        while(t->next){
            t=t->next;
            length++;
        }
        t=head;
        int i=1;
        int pos1=k,pos2=length-k+1;
        while(t){
            if(i==pos1){
                temp1=t;
            }
            if(i==pos2){
                temp2=t;
            }
            t=t->next;
            i++;
        }
        swap(temp1->val,temp2->val);
        return head;
    }
};
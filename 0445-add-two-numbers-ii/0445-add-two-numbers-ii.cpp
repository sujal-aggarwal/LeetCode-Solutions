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
    ListNode* add(ListNode* l1, ListNode* l2,int&carry) {
        if(!l1||!l2){
            return NULL;
        }
        int val=0;
        ListNode*ans=add(l1->next,l2->next,val);
        l1->val+=(l2->val+val);
        carry=l1->val/10;
        l1->val%=10;
        l1->next=ans;
        return l1;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*p1=l1,*p2=l2;
        while(p1||p2){
            if(!p1){
                ListNode*a=new ListNode(0);
                a->next=l1;
                l1=a;
                p2=p2->next;
            }
            else if(!p2){
                ListNode*a=new ListNode(0);
                a->next=l2;
                l2=a;
                p1=p1->next;
            }
            else{
                p1=p1->next;
                p2=p2->next;
            }
        }
        int ans=0;
        ListNode*node=add(l1,l2,ans);
        if(ans){
            ListNode*n=new ListNode(ans);
            n->next=node;
            return n;
        }
        return node;
    }
};
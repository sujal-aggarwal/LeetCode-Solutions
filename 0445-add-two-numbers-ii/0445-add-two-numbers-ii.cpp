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
    ListNode* reverseList(ListNode*l1){
        if(!l1->next){return l1;}
        ListNode*prev=l1->next;
        ListNode *ans=reverseList(l1->next);
        if(prev)
            prev->next=l1;
        l1->next=nullptr;
        return ans;
    }
    ListNode* add(ListNode* l1, ListNode* l2) { 
        int carry=0;
        ListNode*ans=new ListNode();
        ListNode*a=ans;
        while(l1||l2||carry){
            ListNode*temp=new ListNode();
            int a=0;
            if(l1){
                a+=l1->val;
                l1=l1->next;
            }
            if(l2){
                a+=l2->val;
                l2=l2->next;
            }
            a+=carry;
            temp->val=(a%10);
            ans->next=temp;
            ans=temp;
            carry=a/10;
        }
        return a->next;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverseList(l1);
        l2=reverseList(l2);
        return reverseList(add(l1,l2));
    }
};
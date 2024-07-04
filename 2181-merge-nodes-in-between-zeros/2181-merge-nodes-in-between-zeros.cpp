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
    ListNode* tail;
    ListNode* ans;
    void solve(ListNode* head, int currSum){
        if(head==nullptr)return;
        if(head->val==0){
            if(tail==nullptr){
                ans=new ListNode(currSum);
                tail=ans;
            }else{
                tail->next=new ListNode(currSum);
                tail=tail->next;
            }
            currSum=0;
        }else{
            currSum+=head->val;
        }
        solve(head->next,currSum);
    }
    ListNode* mergeNodes(ListNode* head) {
        tail=nullptr;
        ans=nullptr;
        solve(head->next,0);
        return ans;
    }
};
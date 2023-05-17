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
    int pairSum(ListNode* head) {
        stack<int>s;
        int n=0;
        ListNode*temp=head;
        while(temp){
            s.push(temp->val);
            temp=temp->next;
            n++;
        }
        int ans=0;
        for(int i=0;i<n/2;i++){
            ans=max(ans,head->val+s.top());
            s.pop();
            head=head->next;
        }
        return ans;
    }
};
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
    bool isCritical(ListNode* prev,ListNode* curr,ListNode* next){
        return ((prev->val < curr->val) && (next->val < curr->val)) || ((prev->val > curr->val) && (next->val > curr->val));
    }
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int min_val=INT_MAX;
        int i=-1,j=-1;
        int initial_index=-1;
        ListNode* prev_node=head;
        ListNode* curr=head->next;
        int index=1;
        while(curr->next!=nullptr){
            if(isCritical(prev_node,curr,curr->next)){
                if(i<0){
                    i=index;
                    initial_index=index;
                }else{
                    j=index;
                    min_val=min(min_val,j-i);
                    i=index;
                }
            }
            prev_node=curr;
            curr=curr->next;
            index++;
        }
        if(min_val==INT_MAX)return vector<int>{-1,-1};
        return vector<int>{min_val,j-initial_index};
    }
};
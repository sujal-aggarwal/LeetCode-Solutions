/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        vector<ListNode*>arr;
        ListNode*temp=head;
        while(temp!=NULL)
        {
            auto index=find(arr.begin(),arr.end(),temp);
            if(index!=arr.end())
            {
                return temp;
            }
            arr.push_back(temp);
            temp=temp->next;
        }
        return NULL;
    }
};
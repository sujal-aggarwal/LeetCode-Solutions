/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*>q;
        priority_queue<long long>pq;
        q.push(root);
        q.push(NULL);
        long long lvl=1;
        long long sum=0;
        while(!q.empty()){
            TreeNode*curr=q.front();
            q.pop();
            if(curr==NULL){
                pq.push(sum);
                sum=0;
                lvl++;
                if(!q.empty())
                    q.push(NULL);
                continue;
            }
            sum+=curr->val;
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
        if(pq.size()<k){
            return -1;
        }
        int cnt=1;
        while(cnt!=k){
            cnt++;
            pq.pop();
        }
        return pq.top();
    }
};
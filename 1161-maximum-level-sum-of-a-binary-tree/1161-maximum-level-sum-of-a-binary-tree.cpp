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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        int lvl=1;
        int sum=0;
        int max_lvl=0;
        int max_sum=INT_MIN;
        while(!q.empty()){
            TreeNode*curr=q.front();
            q.pop();
            if(curr==NULL){
                if(max_sum<sum){
                    max_sum=sum;
                    max_lvl=lvl;
                }
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
        return max_lvl;
    }
};
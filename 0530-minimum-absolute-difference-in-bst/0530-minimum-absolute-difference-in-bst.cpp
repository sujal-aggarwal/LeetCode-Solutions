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
    int getMinimumDifference(TreeNode* root) {
        if(!root){
            return INT_MAX;
        }
        int a=getMinimumDifference(root->left);
        int b=getMinimumDifference(root->right);
        int ans=INT_MAX;
        if(root->right){
            TreeNode*r=root->right;
            while(r->left){
                r=r->left;
            }
            ans=min(ans,r->val-root->val);
        }
        if(root->left){
            TreeNode*l=root->left;
            while(l->right){
                l=l->right;
            }
            ans=min(ans,root->val-l->val);
        }
        return min({a,b,ans});
    }
};
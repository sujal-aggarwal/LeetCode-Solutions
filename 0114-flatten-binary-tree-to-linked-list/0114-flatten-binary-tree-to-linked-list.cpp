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
    TreeNode* solve(TreeNode*root){
        if(root==NULL)return NULL;
        TreeNode*left=solve(root->left);
        TreeNode*right=solve(root->right);
        root->left=NULL;
        root->right=left;
        TreeNode*temp=root;
        while(temp->right!=NULL){
            temp=temp->right;
        }
        temp->right=right;
        return root;
    }
    void flatten(TreeNode* root) {
        solve(root);
    }
};
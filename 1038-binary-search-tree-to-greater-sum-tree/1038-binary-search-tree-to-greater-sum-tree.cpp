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
    int Sum(TreeNode* root, int a){
        if(root==NULL)return a;
        int sum=Sum(root->right,a);
        root->val=root->val+sum;
        int sum2=Sum(root->left,root->val);
        return sum2;
    }
    TreeNode* bstToGst(TreeNode* root) {
        Sum(root,0);
        return root;
    }
};
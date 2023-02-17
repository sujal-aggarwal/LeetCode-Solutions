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
    void List(vector<int>&ans,TreeNode*root){
        if(root==NULL)
            return ;
        List(ans,root->left);
        ans.push_back(root->val);
        List(ans,root->right);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int>ans;
        List(ans,root);
        int m=INT_MAX;
        for(int i=0;i<ans.size()-1;i++)
        {
            m=min(m,abs(ans[i+1]-ans[i]));
        }
        return m;
    }
};
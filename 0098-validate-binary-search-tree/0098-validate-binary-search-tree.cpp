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
    long  INF_MAX=10e11;
    long  INF_MIN=-10e11;
    pair<pair<long ,long >,bool> ValidBST(TreeNode*root)
    {
        if(root==NULL)
        {
            return {{INF_MAX,INF_MIN},true};
        }
        pair<pair<long ,long >,bool> p1=ValidBST(root->left);
        pair<pair<long ,long >,bool> p2=ValidBST(root->right);
        long  left_max=p1.first.second;
        long  right_min=p2.first.first;
        bool value=((root->val>left_max)&&(root->val<right_min)&&p1.second&&p2.second);
        pair<pair<long ,long >,bool>ans;
        ans.first.second=max(left_max,max(long(root->val),p2.first.second));
        ans.first.first=min(right_min,min(long(root->val),p1.first.first));
        ans.second=value;
        return ans;
    }
    bool isValidBST(TreeNode* root) {
        return ValidBST(root).second;
    }
};
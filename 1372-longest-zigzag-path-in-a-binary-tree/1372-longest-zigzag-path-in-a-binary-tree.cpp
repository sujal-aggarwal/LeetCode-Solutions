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
    int ans=0;
    void Length(TreeNode*root,int steps,bool left){
        if(!root){
            return ;
        }
        ans=max(ans,steps);
        if(left==true){
            Length(root->left,steps+1,false);
            Length(root->right,1,true);
        }else{
            Length(root->right,steps+1,true);
            Length(root->left,1,false);
        }
    }
    
    int longestZigZag(TreeNode* root) {
        Length(root->right,1,true);
        Length(root->left,1,false);
        return ans;
    }
};
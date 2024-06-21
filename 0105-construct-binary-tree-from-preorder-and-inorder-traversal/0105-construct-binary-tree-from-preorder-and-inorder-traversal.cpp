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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& preIndex, int inStart,int inEnd){
        if(inStart>inEnd){
            return nullptr;
        }
        int inMid=inStart;
        while(inorder[inMid]!=preorder[preIndex])inMid++;
        preIndex++;
        TreeNode* root=new TreeNode(inorder[inMid]);
        root->left=solve(preorder,inorder,preIndex,inStart,inMid-1);
        root->right=solve(preorder,inorder,preIndex,inMid+1,inEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        int Ind=0;
        return solve(preorder,inorder,Ind,0,n-1);
    }
};
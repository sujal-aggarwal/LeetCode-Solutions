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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* curr = root;
        while (curr!=NULL) {
            if (curr->right ==NULL) {
                 result.push_back(curr->val);
                curr = curr->left;
            } else {
                TreeNode* leftchild = curr->right;
                while (leftchild->left!=NULL) {
                    leftchild=leftchild->left;
                }
                leftchild->left = curr->left;
                TreeNode* temp = curr;
                result.push_back(curr->val); 
                curr = curr->right;
                temp->right = NULL;
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
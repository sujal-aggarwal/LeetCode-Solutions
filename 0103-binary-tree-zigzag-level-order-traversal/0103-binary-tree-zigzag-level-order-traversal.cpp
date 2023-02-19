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
    void print(deque<TreeNode*>q){
        while(!q.empty()){
            cout<<q.front()->val<<" ";
            q.pop_front();
        }
        cout<<endl;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)
            return vector<vector<int>>();
        vector<vector<int>>arr;
        deque<TreeNode*>q;
        q.push_back(root);
        int level=0;
        while(!q.empty()){
            if(level%2==0){
                vector<int>a;
                deque<TreeNode*>q2;
                while(!q.empty()){
                    TreeNode*front=q.front();
                    q.pop_front();
                    a.push_back(front->val);
                    if(front->left){
                        q2.push_front(front->left);
                    }
                    if(front->right){
                        q2.push_front(front->right);
                    }
                }
                print(q2);
                arr.push_back(a);
                q=q2;
                level++;
            }
            else{
                vector<int>a;
                deque<TreeNode*>q2;
                while(!q.empty()){
                    TreeNode*front=q.front();
                    q.pop_front();
                    a.push_back(front->val);
                    if(front->right){
                        q2.push_front(front->right);
                    }
                    if(front->left){
                        q2.push_front(front->left);
                    }
                }
                print(q2);
                arr.push_back(a);
                q=q2;
                level++;
            }
        }
        return arr;
    }
};
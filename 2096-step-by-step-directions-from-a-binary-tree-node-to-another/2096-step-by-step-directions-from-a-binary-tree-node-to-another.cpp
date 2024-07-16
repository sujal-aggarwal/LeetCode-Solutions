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
    bool directions(TreeNode* root,int destination, string& s){
        if(root==nullptr)return false;
        if(root->val==destination){
            return true;
        }
        s+='L';
        bool left=directions(root->left,destination,s);
        if(left){
            return true;
        }
        s.pop_back();
        s+='R';
        bool right=directions(root->right,destination,s);
        if(right){
            return true;
        }
        s.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string start="";
        directions(root,startValue,start);
        string destination="";
        directions(root,destValue,destination);
        string ans="";
        int index=0;
        while(index<min(destination.length(),start.length()) && destination[index]==start[index]){
            index++;
        }
        for(int i=index;i<start.length();i++){
            ans+='U';
        }
        if(index<destination.length())
            ans+=destination.substr(index);
        return ans;
    }
};
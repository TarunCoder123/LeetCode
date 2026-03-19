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
    pair<int,bool> solve(TreeNode* root){
        if(root==NULL)return {0,true};
        pair<int,bool> p1=solve(root->left);
        pair<int,bool> p2=solve(root->right);
        int height=max(p1.first,p2.first)+1;
        bool value=(abs(p1.first-p2.first)<=1);
        return {height,value && p1.second && p2.second};
    }
    bool isBalanced(TreeNode* root) {
      pair<int,bool> v=solve(root);
      return v.second;
    }
};
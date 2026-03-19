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
    pair<int,int> solve(TreeNode* node){
        if(node==NULL)return {0,0};
        pair<int,int> l1=solve(node->left);
        pair<int,int> l2=solve(node->right);
        int height=1+max(l1.first,l2.first);
        int width=max(l1.second,max(l2.second,l1.first+l2.first));
        return {height,width};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        // the pair is first of height and second one is for depth
       pair<int,int> v=solve(root);
       return v.second;
    }
};
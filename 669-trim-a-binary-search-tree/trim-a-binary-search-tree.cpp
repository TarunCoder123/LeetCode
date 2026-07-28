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
    TreeNode* solve(TreeNode* root,int low,int high){
        // base case
        if(root==NULL)return root;
        TreeNode* value1=solve(root->left,low,high);
        TreeNode* value2=solve(root->right,low,high);
        if(root->val<low){
            return value2;
        }else if(root->val>high){
            return value1;
        }
        root->left=value1;
        root->right=value2;
        return root;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
         return solve(root,low,high);
    }
};
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
    TreeNode* solve2(vector<int> arr,int s,int e){
        if(s>e){
            return NULL;
        }
        int mid=s+(e-s)/2;
        TreeNode* root=new TreeNode(arr[mid]);
        root->left=solve2(arr,s,mid-1);
        root->right=solve2(arr,mid+1,e);
        return root;
    }
    void solve(vector<int> &arr,TreeNode* root){
        if(root==NULL)return;
        solve(arr,root->left);
        arr.push_back(root->val);
        solve(arr,root->right);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        solve(arr,root);

        return solve2(arr,0,arr.size()-1);

    }
};
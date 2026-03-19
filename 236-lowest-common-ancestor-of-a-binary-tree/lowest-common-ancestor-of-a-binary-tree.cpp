/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findPath(TreeNode* root,TreeNode* target,vector<TreeNode*> &path){
        if(root==NULL)return false;
        cout<<root->val<<" root->val "<<target->val<<" target->val "<<path.size()<<" path.size() "<<endl;

        path.push_back(root);

        if(root==target)return true;

        if(findPath(root->left,target,path)|findPath(root->right,target,path))return true;

        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1,path2;

        findPath(root,p,path1);
        for(auto it:path1){
            cout<<it<<" it "<<endl;
        }
        findPath(root,q,path2);

        int i=0;
        for(;i<path1.size()&&i<path2.size();i++){
            if(path1[i]!=path2[i])break;
        }

        return path1[i-1];

    }
};
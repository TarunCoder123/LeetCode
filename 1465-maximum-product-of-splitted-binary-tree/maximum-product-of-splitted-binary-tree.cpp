class Solution {
public:
    long long findSum(TreeNode* root) {
        if (!root) return 0;
        return findSum(root->left) + findSum(root->right) + root->val;
    }

    long long findMaxi(TreeNode* root, long long &maxi, long long sum) {
        if (!root) return 0;

        long long leftSum = findMaxi(root->left, maxi, sum);
        long long rightSum = findMaxi(root->right, maxi, sum);

        maxi = max(maxi, leftSum * (sum - leftSum));
        maxi = max(maxi, rightSum * (sum - rightSum));

        return leftSum + rightSum + root->val;
    }

    int maxProduct(TreeNode* root) {
        long long sum = findSum(root);
        long long maxi = 0;
        findMaxi(root, maxi, sum);

        return maxi % 1000000007; 
    }
};

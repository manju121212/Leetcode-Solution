class Solution {
public:
    long long total = 0;
    long long ans = 0;

   
    long long findTotal(TreeNode* root){
        if(!root) return 0;
        return root->val + findTotal(root->left) + findTotal(root->right);
    }

   
    long long solve(TreeNode* root){
        if(!root) return 0;

        long long left = solve(root->left);
        long long right = solve(root->right);

        long long subsum = left + right + root->val;

        ans = max(ans, subsum * (total - subsum));

        return subsum;
    }

    int maxProduct(TreeNode* root) {
        total = findTotal(root);
        solve(root);

        return ans % 1000000007;
    }
};

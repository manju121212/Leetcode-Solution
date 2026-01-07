class Solution {
public:
    long long maxi = 0;

   
    void solve(TreeNode* root , long long &sum){
        if(root == NULL) return ;
        solve(root->left , sum);
        sum += root->val;
        solve(root->right , sum);
    }

   
    long long solve1(TreeNode* root , long long totalsum){
        if(root == NULL) return 0;

        long long left = solve1(root->left, totalsum);
        long long right = solve1(root->right, totalsum);

        long long subsum = left + right + root->val;

        maxi = max(maxi, subsum * (totalsum - subsum));

        return subsum;
    }

    int maxProduct(TreeNode* root) {
        long long totalsum = 0;
        solve(root, totalsum);

        solve1(root, totalsum);

        return maxi % 1000000007;
    }
};

class Solution {
public:
    int count = 0;

    int solve(TreeNode* root){

        if(root == NULL){
            return INT_MIN;
        }

        if(root->left == NULL && root->right == NULL){
            count++;
            return root->val;
        }

        int left = solve(root->left);
        int right = solve(root->right);

        if(root->val >= left && root->val >= right){
            count++;
        }

        return max({root->val, left, right});
    }

    int countDominantNodes(TreeNode* root) {

     

        solve(root);

        return count;
    }
};
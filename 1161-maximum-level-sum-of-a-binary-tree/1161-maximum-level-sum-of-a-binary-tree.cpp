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
    int maxLevelSum(TreeNode* root) {
        
        queue<TreeNode*>q;
        q.push(root);
        int maxi = -1e9;
        int curr = 0;
        int level = -1;
        while(!q.empty()){
              int size = q.size();
              int sum = 0;
              curr++;
              for(int i = 0;i<size;i++){
                    TreeNode* node = q.front();
                    sum +=node->val;
                    q.pop();
                    if(node->left != NULL){
                           q.push(node->left);
                    }
                    if(node->right != NULL){
                          q.push(node->right);
                    }
              }

              if(maxi<sum){
                  maxi = sum;
                  level = curr;
              }
        }

        return level;
    }
};
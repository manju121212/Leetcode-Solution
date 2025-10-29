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
    void printInorder(TreeNode* node,vector<int> &ans)
{
    if (node == NULL)
        return;
  
    
    printInorder(node->left,ans);
    ans.push_back(node->val);
    printInorder(node->right,ans);
}
    
    
    bool findTarget(TreeNode* root, int k) {
        vector<int>ans;
        printInorder(root,ans);
        
        int i=0;
        int j=ans.size()-1;
        
        while(i<j){
            int sum=ans[i]+ans[j];
            if(sum==k){
                 return true;
            }
            else if(k>sum){
                i++;
            }
            else{
                j--;
            }
        }
        
        return false;
    }
    
};
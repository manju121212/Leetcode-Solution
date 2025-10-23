class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        long long maxi = 0;
        queue<pair<TreeNode*, long long>> q;  // pair of (node, index)
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            long long left = q.front().second;   // leftmost index
            long long right = left;              // rightmost index (initialize)
            
            // optional, if you want to "simulate" your previous 'mult' approach
            // think of 'mult' as how we normalize indexes to avoid overflow
            long long base = left;

            for (int i = 0; i < size; i++) {
                auto [node, idx] = q.front();
                q.pop();
                idx -= base; // normalize index for this level

                // Update rightmost position
                right = idx;

                // Push children with complete-tree style indices
                if (node->left)
                    q.push({node->left, 2 * idx});
                if (node->right)
                    q.push({node->right, 2 * idx + 1});
            }

            // Width = rightmost_index - leftmost_index + 1
            long long width = right - 0 + 1;
            maxi = max(maxi, width);
        }

        return (int)maxi;
    }
};

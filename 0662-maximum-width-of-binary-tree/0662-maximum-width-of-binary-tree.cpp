class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        int ans = 0;
        // Queue stores (node, index in virtual complete tree)
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});  // root index = 0

        while (!q.empty()) {
            int size = q.size();
            unsigned long long first = q.front().second; // leftmost node index
            unsigned long long last = first;            // rightmost node index

            for (int i = 0; i < size; i++) {
                auto [node, idx] = q.front();
                q.pop();

                last = idx;  // update rightmost node index

                if (node->left)
                    q.push({node->left, 2 * idx + 1});   // left child
                if (node->right)
                    q.push({node->right, 2 * idx + 2});  // right child
            }

            // Width = rightmost - leftmost + 1
            ans = max(ans, (int)(last - first + 1));
        }

        return ans;
    }
};

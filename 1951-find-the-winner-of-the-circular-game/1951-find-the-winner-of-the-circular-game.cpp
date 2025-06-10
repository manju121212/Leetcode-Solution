class Solution {
public:
    void solve(int num, int oper, int k, int n, unordered_map<int, int>& vis, unordered_map<int, int>& res) {
        if (res.size() == 1) return;

        for (int i = num;; i++) {
            int j = (i - 1) % n + 1;  // Wrap around circle (1 to n)

            if (vis.find(j) == vis.end()) {
                oper++;

                if (oper == k) {
                    vis[j]++;
                    res.erase(j);

                    int next = j + 1;
                    if (next > n) next = 1;

                    // Recursive call with oper reset to 0 after elimination
                    solve(next, 0, k, n, vis, res);
                    break;
                }
            }
        }
    }

    int findTheWinner(int n, int k) {
        unordered_map<int, int> vis;
        unordered_map<int, int> res;

        for (int i = 1; i <= n; i++) {
            res[i]++;
        }

        solve(1, 0, k, n, vis, res);

        for (auto it : res) {
            return it.first;
        }

        return -1; // Just in case
    }
};
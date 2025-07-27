class Solution {
public:
    long long numOfSubsequences(string s) {
        int n = s.size();
        vector<int> prefix_L(n, 0);
        vector<int> suffix_T(n, 0);

        prefix_L[0] = s[0] == 'L' ? 1 : 0;
        for (int i = 1; i < n; i++) {
            prefix_L[i] = prefix_L[i - 1] + (s[i] == 'L' ? 1 : 0);
        }

        suffix_T[n - 1] = s[n - 1] == 'T' ? 1 : 0;
        for (int i = n - 2; i >= 0; i--) {
            suffix_T[i] = suffix_T[i + 1] + (s[i] == 'T' ? 1 : 0);
        }

        long long maxOutput_L = 0, maxOutput_T = 0,maxOutput_C = 0;
       
        for (int i = 0; i < n; i++) {
            if (s[i] == 'C') {
                long long count_L = prefix_L[i];
                long long count_T = suffix_T[i];

                maxOutput_L += (count_L + 1) * count_T; // Insert 'L' before
                maxOutput_T += (count_T + 1) * count_L; // Insert 'T' after
                 maxOutput_C += count_T* count_L; // Insert 'C' 

            }
        }

        long long best = 0;
        for (int i = 0; i <= n; i++) {
            long long count_L = (i == 0) ? 0 : prefix_L[i - 1];
            long long count_T = (i == n) ? 0 : suffix_T[i];
            best = max(best, count_L * count_T);
        }

        return max({maxOutput_L, maxOutput_T, best + maxOutput_C});
    }
};

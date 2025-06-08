class Solution {
public:
    const int MOD = 1e9 + 7;

    long long factorial(int n) {
        if(n == 0 || n == 1)
          return 1LL;
        
        return (1LL * n * factorial(n - 1)) % MOD;
    }

    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();

       
        for (int i = 1; i < n; i++) {
            bool canUnlock = false;
            for (int j = 0; j < i; j++) {
                if (complexity[j] < complexity[i]) {
                    canUnlock = true;
                    break;
                }
            }
            if (!canUnlock) return 0; 
        }

        
        return factorial(n - 1); 
    }
};

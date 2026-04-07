class Solution {
public:
    vector<int> findGoodIntegers(int n) {
         int limit = cbrt(n);
     

        unordered_map<int, int> count;

        for (int a = 1; a <= limit; a++) {
            long long a3 = 1LL * a * a * a;

            for (int b = a; b <= limit; b++) {
                long long sum = a3 + 1LL * b * b * b;

                if (sum > n) break;
                count[(int)sum]++;
            }
        }

        vector<int> res;
        for (auto &it : count) {
            if (it.second >= 2) {
                res.push_back(it.first);
            }
        }

        sort(res.begin(), res.end());
        return res;
    }
};
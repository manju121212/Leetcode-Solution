class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;
        long long sum = 0;

        vector<int> left(n, 1), right(n, 1);
        stack<int> st;

        // left
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            left[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // right
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            right[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }

        // final sum (no initial sum now)
        for(int i = 0; i < n; i++){
            long long freq = 1LL * left[i] * right[i];
            sum = (sum + arr[i] * freq) % MOD;
        }

        return (int)sum;
    }
};

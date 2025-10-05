class Solution {
public:
    string removeSubstring(string s, int k) {
        stack<pair<char,int>> st;

        for(char next: s) {
            // add
            if(st.empty() || next != st.top().first) {
                st.push({next, 1});
            } else {
                auto [c, cnt] = st.top(); st.pop();
                st.push({c, cnt+1});
            }
            // merge
            if(st.size()>1) {
                auto [b, bcnt] = st.top(); st.pop();
                auto [a, acnt] = st.top(); st.pop();
                if(a=='(' && b==')' && acnt >= k && bcnt >= k) {
                    acnt -= k;
                    bcnt -= k;
                }
                if(acnt>0)
                    st.push({a, acnt});
                if(bcnt>0)
                    st.push({b, bcnt});
            }
        }

        string ans;
        while(!st.empty()) {
            auto [c, cnt] = st.top(); st.pop();
            ans += string(cnt, c);
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
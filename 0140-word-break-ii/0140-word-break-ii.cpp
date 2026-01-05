

class Solution {
public:
    vector<string> result;
    unordered_set<string> st;
    string str;

    void backtrack(int index, string curr) {
        if (index == str.length()) {
            result.push_back(curr);
            return;
        }

        for (int i = index; i < str.length(); i++) {
            string word = str.substr(index, i - index + 1);
            if (st.count(word)) {
                string next = curr.empty() ? word : curr + " " + word;
                backtrack(i + 1, next);
            }
        }
    }

      vector<string> wordBreak(string s, vector<string>& wordDict)  {
        str = s;
        for (auto &w : wordDict) st.insert(w);
        backtrack(0, "");
        return result;
    }
};

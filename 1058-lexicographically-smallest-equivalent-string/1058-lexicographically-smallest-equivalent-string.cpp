class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x)
            return parent[x] ;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;

        // Always keep the smaller char as parent
        if (px < py)
            parent[py] = px;
        else
            parent[px] = py;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.resize(26);
        for (int i = 0; i < 26; i++)
            parent[i] = i;

        for (int i = 0; i < s1.length(); i++) {
            unite(s1[i] - 'a', s2[i] - 'a');
        }

        string res;
        for (char c : baseStr) {
            int smallest = find(c - 'a');
            res += (char)(smallest + 'a');
        }

        return res;
    }
};

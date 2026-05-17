class Solution {
public:

    bool dfs(int idx, vector<int>& arr, vector<int>& vis) {

        if(idx < 0 || idx >= arr.size() || vis[idx])
            return false;

        if(arr[idx] == 0)
            return true;

        vis[idx] = 1;

        int forward = idx + arr[idx];
        int backward = idx - arr[idx];

        return dfs(forward, arr, vis) || dfs(backward, arr, vis);
    }

    bool canReach(vector<int>& arr, int start) {

        vector<int> vis(arr.size(), 0);

        return dfs(start, arr, vis);
    }
};
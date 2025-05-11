class Solution {
public:

    vector<int> findRightInterval(vector<vector<int>>& intervals) {
      
        int n = intervals.size();
        vector<pair<int,int>>ans;
        for(int i = 0;i<n;i++){
            int u = intervals[i][0];
            int v = intervals[i][1];
            ans.push_back({u,i});
        }
        sort(ans.begin(),ans.end());

        vector<int>res(n,-1);
        for(int i = 0;i<n;i++){
            int end_i = intervals[i][1];
            pair<int,int>target = {end_i,0};
            
            auto it = lower_bound(ans.begin(),ans.end(),target);

            if(it != ans.end()){
                  int index = (*it).second;
                  res[i] = index;
            }
            
        }

        return res;

        return res;
    }
};
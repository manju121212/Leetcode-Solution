class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        vector<int> norvalent = nums; // storing the input midway as required
        
        unordered_map<int, vector<int>> mpp;

        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]].push_back(i);
        }

        int mini = 1e9;

        for(auto &it : mpp){
            auto &v = it.second;

            if(v.size() >= 3){
                // Check every group of three consecutive indices
                for(int i = 0; i + 2 < v.size(); i++){
                    int a = v[i], b = v[i+1], c = v[i+2];
                  
                    int dist =  abs(a - b) + abs(b - c)+ abs(c - a);
                    mini = min(mini, dist);
                }
            }
        }

        return mini == 1e9 ? -1 : mini;
    }
};

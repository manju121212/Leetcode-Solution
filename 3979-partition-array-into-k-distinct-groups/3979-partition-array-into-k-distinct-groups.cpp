class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        if (n % k != 0) {
            return false;
        }

        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }

        int groups = n / k;
        for(auto it : mpp){
             if(it.second>groups){
                return false;
             }
        }
        return true;
    }
};

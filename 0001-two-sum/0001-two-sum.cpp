class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mpp;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            mpp[nums[i]] = i;
        }
        vector<int>res;
        for(int i = 0;i<n;i++){
            int value = target-nums[i];
            if( mpp.find(value) != mpp.end()&& i!= mpp[value]){
                   res.push_back(i);
                   res.push_back(mpp[value]);
                   break;
            }
        }
        return res;
    }
};
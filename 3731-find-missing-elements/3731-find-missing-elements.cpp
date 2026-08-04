class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_map<int,int>mpp;
        vector<int>res;
        int mini = *min_element(nums.begin(),nums.end());
        int maxi = *max_element(nums.begin(),nums.end());

        for(auto it : nums){
             mpp[it]++;
        }
        int count = mini;

        while(count<=maxi){
             if(mpp.find(count) == mpp.end()){
                  res.push_back(count);
             }
             count++;
        }

        return res;
    }
};
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        
         sort(nums.begin(),nums.end());
         int n = nums.size();
         vector<int>prefix(n,0);
         prefix[0] = nums[0];

        for(int i = 1;i<n;i++){
               
             prefix[i] = prefix[i-1] + nums[i];
        }
        vector<int>res;
        for(int i = 0;i<queries.size();i++){

            int index = upper_bound(prefix.begin(),prefix.end(),queries[i]) - prefix.begin();
            res.push_back(index);

        }

        return res;
    }
};
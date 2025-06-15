class Solution {
public:
int mod = 1e9+7;
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,vector<int>>mpp;
        long long count = 0;
        for(int i = 0;i<n;i++){
            mpp[nums[i]].push_back(i);
        }


        for(int i = 1;i<n-1;i++){
             int target = nums[i]*2;

             if(mpp.find(target) == mpp.end()){
                   continue;
             }

             int left = lower_bound(mpp[target].begin(),mpp[target].end(),i) - mpp[target].begin();
           
             cout<<left<<endl;
             int right = mpp[target].size() - left;
             if(target == nums[i]){
                right--;
             }

             count += (long long)left*right;
             count = count%mod;
             
        }

        return count;
    }
};
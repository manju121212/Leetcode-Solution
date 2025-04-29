class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        int j = 0;
        int i = 0;
        long long count = 0;
        int n = nums.size();
        unordered_map<int,int>mpp;
        int maxi = *max_element(nums.begin(),nums.end());
        
        while(j<n){
            
           
            mpp[nums[j]]++;
            while(mpp[maxi]>=k){
                count += (n-j);
                mpp[nums[i]]--;
                i++;

            }
            j++;
        }

        return count;
    }
};
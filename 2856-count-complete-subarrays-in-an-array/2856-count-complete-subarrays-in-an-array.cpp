class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int>st;
        unordered_map<int,int>mpp;
        int n = nums.size();
        for(auto it : nums){
            st.insert(it);
        }
        int c = st.size();

        int i = 0;
        int j = 0;
        int count = 0;
        while(j<n){
             mpp[nums[j]]++;
           
                   
                   while(mpp.size() == c){
                        count +=(n-j);
                        mpp[nums[i]]--;

                        if(mpp[nums[i]] == 0){
                            mpp.erase(nums[i]);
                        }
                        i++;
                   }
             
             j++;
        }

        return count;
    }
};
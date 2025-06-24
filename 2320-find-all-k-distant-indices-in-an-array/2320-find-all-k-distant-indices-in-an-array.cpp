class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
           int n = nums.size();
           vector<int>res;
           set<int>st;
           for(int i = n-1;i>=0;i--){
            if(nums[i] != key){
                continue;
            }
                for(int j = 0;j<n;j++){
                      int distant = abs(i-j);
                      if(distant<=k){
                            st.insert(j);
                      }
                }
           }
          
           for(auto it : st){
                res.push_back(it);
           }
           return res;
    }
};
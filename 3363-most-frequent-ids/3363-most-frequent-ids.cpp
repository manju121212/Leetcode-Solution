class Solution {
public:
    typedef pair<long long,int> T;
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        priority_queue<T> pq;
        unordered_map<int,long long> mpp;
        unordered_map<int,bool> vis;

        int n = nums.size();
        vector<long long> res(n,0);

        for(int i = 0; i < n; i++){
            int e = nums[i];
            long long f = freq[i];
            // update current frequency
            mpp[e] += f;

           
                pq.push({mpp[e], e});
          
           
            // lazy removal of outdated tops
            while(!pq.empty()){
                auto topPair = pq.top();
                if(mpp[topPair.second] != topPair.first) {
                    pq.pop(); // outdated, remove it
                } else {
                    break;    // valid top
                }
            }

            if(pq.empty()) res[i] = 0;
            else           res[i] = pq.top().first;
        }

        return res;
    }
};

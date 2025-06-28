class Solution {
public:
    typedef pair<int, int> pi;
    static bool cmp(pair<int,int>&a,pair<int,int>&b){
         if(a.first == b.first){
               return a.second>b.second;
         }
          else if(a.first > b.first){
               return true;
          }

          return false;
    }
    vector<int> maxSubsequence(vector<int>& nums, int k) {
          vector<pair<int,int>>v;
          int n = nums.size();

          for(int i = 0;i<n;i++){
               v.push_back({nums[i],i});
          }
          sort(v.begin(),v.end(),cmp);

          vector<int>res;
          
        
          priority_queue<pi, vector<pi>, greater<pi> > pq;
          for(int i = 0;i<k;i++){
               int index = v[i].second;
               int value = v[i].first;
               pq.push({index,value});
          }

          while(!pq.empty()){
              res.push_back(pq.top().second);
              pq.pop();
          }
          
          return res;
    }
};
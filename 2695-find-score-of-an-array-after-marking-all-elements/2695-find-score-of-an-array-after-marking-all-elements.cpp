class Solution {
public:
     typedef pair<int,int>T;
     struct cmp {
            bool operator()(const T& a, const T& b) const {
                if (a.first == b.first) {
                    return a.second > b.second; 
                }
                return a.first > b.first;       
            }
     };
    long long findScore(vector<int>& nums) {
        
        priority_queue<T,vector<T>,cmp>pq;
        int n = nums.size();
        for(int i = 0;i<n;i++){
              pq.push({nums[i],i});
        }
        long long sum = 0;
        unordered_map<int,bool>vis;
        while(!pq.empty()){
             int ele = pq.top().first;
             int index = pq.top().second;
             //cout<<ele<<"->"<<index<<"->"<<vis[index]<<endl;
             pq.pop();
             
             if(vis[index] == 0){
                 sum +=ele;
                 vis[index] = true;
                 if(index-1>=0){
                    vis[index-1] = true;
                 }
                 if(index+1<n){
                     vis[index+1] = true;
                 }
             }
        }

        return sum ;
    }
};
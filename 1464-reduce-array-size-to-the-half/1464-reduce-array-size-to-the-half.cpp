class Solution {
public:
    int minSetSize(vector<int>& arr) {
       priority_queue<pair<int,int>>pq;
       unordered_map<int,int>mpp;
       int n = arr.size();
       int totalsum = 0;
       for(int i = 0;i<n;i++){
            mpp[arr[i]]++;
            
       } 

       for(auto it : mpp){
          totalsum +=it.second;
          pq.push({it.second,it.first});
       }
       int count = 0;
       while(!pq.empty()){
            int ele = pq.top().second;
            int freq = pq.top().first;
            pq.pop();
            cout<<ele<<endl;

            totalsum -=freq;
            count++;
            if(totalsum<=(n/2)){
                  return count;
            }


       }

       return count;
    }
};
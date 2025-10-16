class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mpp;
        int count = 0;
        priority_queue<int> pq;
        unordered_map<char, int> vis;

        for (char task : tasks) {
            mpp[task]++;
        }

        for (auto it : mpp) {
            pq.push(it.second);
        }

        int i = 0;
        int time = 0;
        while (!pq.empty()) {
                vector<int>temp;
                for(int i = 1;i<=n+1;i++){
                       
                       if(!pq.empty()){
                           int freq = pq.top();
                           pq.pop();
                           freq--;
                           temp.push_back(freq);
                       }
                }


                for(auto it : temp){
                      if(it>0){
                          pq.push(it);
                      }
                }

                if(pq.empty()){
                      time +=temp.size();
                }
                else{
                      time +=n+1;
                }
        }

        return time;
    }
};

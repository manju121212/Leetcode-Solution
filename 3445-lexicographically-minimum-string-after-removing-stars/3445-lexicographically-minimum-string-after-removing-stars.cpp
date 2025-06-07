class Solution {
public:
    struct cmp {
    bool operator()(pair<char, int>& a, pair<char, int>& b) {
        if (a.first == b.first) {
            return a.second < b.second;  // prefer higher index
        }
        return a.first > b.first;  // prefer smaller char (lex order)
    }
};
    string clearStars(string s) {
         priority_queue<pair<char,int>,vector<pair<char,int>>,cmp>pq;  
         int n = s.size();
         string res = "";
         vector<int>notTake(n,0);
         for(int i = 0;i<n;i++){
             
             if(s[i] != '*'){
                 pq.push({s[i],i});
             }
             else{
                if(!pq.empty()){
                    pair<char,int>p = pq.top();
                    pq.pop();
                    notTake[p.second]= -1;
                }
               
             }

         }


         for(int i = 0;i<n;i++){
              if(notTake[i] != -1 && s[i] != '*'){
                     res += s[i];
              }
         }
         return res; 
    }
};
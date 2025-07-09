class Solution {
public:
    vector<int>ans;
    void solve(int num ,int prev, int len , int k){
            if(len == 0){
                  ans.push_back(num);
                  return;
            }

            for(int i = 0;i<=9;i++){
                  
                  if(abs(i-prev) == k){
                       solve(num*10 + i ,i ,len-1,k);
                  }
            }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
          

          for(int i = 1;i<=9;i++){
               solve(i,i,n-1,k);
          }

          return ans;
    }
};
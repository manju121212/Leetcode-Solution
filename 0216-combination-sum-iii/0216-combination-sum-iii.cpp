class Solution {
public:
    vector<vector<int>>ans;
    void solve(int ele , int sum , int len , int n,vector<int>temp){
        if(len == 0){


           for(int i = 0;i<temp.size();i++){
               cout<<temp[i]<<",";
           }
           cout<<endl;
            if(sum == n){
                ans.push_back(temp);
            }
            return;
        }

        for(int i = ele;i<=9;i++){
               if(sum+i<=n){
                   temp.push_back(i);
                   solve(i+1,sum+i,len-1,n,temp);
                   temp.pop_back();
               }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
          vector<int>temp;
          solve(1,0,k,n,temp);
          return ans;
    }
};
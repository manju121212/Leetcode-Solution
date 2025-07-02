class Solution {
public:

    void solve(int index , int prev , vector<int>temp,set<vector<int>>&res,vector<int>&nums,int n){
         if(index>=n){
              if(temp.size()>1){
                  res.insert(temp);
              }
              return;
         }

         if(temp.size() ==0 || (temp.back()<=nums[index])){
            
               temp.push_back(nums[index]);
               solve(index+1,nums[index],temp,res,nums,n);
               temp.pop_back();
               
               
         }
         
       
       
         solve(index+1,prev,temp,res,nums,n);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        set<vector<int>>res;
        vector<int>temp;
        int n = nums.size();
        

        solve(0,-1,temp,res,nums,n);
        //sort(res.begin(),res.end());
         return vector<vector<int>>(res.begin(), res.end());
        
    }
};
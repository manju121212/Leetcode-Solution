class Solution {
public:
string result = "";
    bool solve(string temp, unordered_map<string,int>&vis, int n){
        if(temp.size() == n){
             if(vis.find(temp) == vis.end()){
                result = temp;
                return false;
             }

            temp = "";
            return false;
        }
 
      if(solve(temp+'0',vis,n) == true){
           return true;
      } 
     
      if(solve(temp+'1',vis,n) == true){
          return true;
      }

      return false;
       

        
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
     
         unordered_map<string,int>vis;
         for(auto it : nums){
            vis[it]++;
         }
    
         string temp = "";
         bool res = solve(temp,vis,n);

         return result;
    }
};
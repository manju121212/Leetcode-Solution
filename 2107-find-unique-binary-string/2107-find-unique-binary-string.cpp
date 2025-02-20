class Solution {
public:
string result = "";
    bool solve(string &temp, unordered_map<string,int>vis, int n){
        if(temp.size() == n){
            cout<<temp<<endl;
            if(vis[temp] == 0){
                  result = temp;
                  return true;
            }
            return false;
        }
        temp.push_back('0');
        if(solve(temp,vis,n) == true){
            return true;
        } 
        temp.pop_back();
          temp.push_back('1');
         if(solve(temp,vis,n) == true){
            return true;
        }
          temp.pop_back();

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
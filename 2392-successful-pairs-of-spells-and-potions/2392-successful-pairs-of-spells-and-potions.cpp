class Solution {
public:
    int mod = 1e9+7;
    int bs(long long ele , vector<int>&potions,long long success){
             
             int low = 0;
             int high = potions.size()-1;
             int res = -1;
             while(low<=high){
                  int mid = low + (high - low)/2;
                  long long tar = potions[mid]*ele;
                  if(tar >=success){
                        res = mid;
                        high = mid-1;
                  }
                  else{
                    low = mid+1;
                  }
             }
             cout<<res<<endl;

            if(res == -1){return 0;
            }
             return potions.size()-res;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
          
          int n = spells.size();
          vector<int>ans;
          sort(potions.begin(),potions.end());
          for(int i = 0;i<n;i++){
               
               int res = bs(spells[i],potions,success);
               ans.push_back(res);

          }

          return ans;
    }
};
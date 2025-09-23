class Solution {
public:
    int totalFruit(vector<int>& fruits) {


         int left = 0;
         int right = 0;
         int count = 0;
         int n = fruits.size();
         unordered_map<int,int>mpp;
         while(right<n){
              mpp[fruits[right]]++;

              while(left<right && mpp.size() > 2){
                   mpp[fruits[left]]--;
                   if(mpp[fruits[left]] == 0){
                          mpp.erase(fruits[left]);
                   }
                   left++;
              }

              count = max(count , right - left+1);
              right++;
         }

         return count;     
    }
};
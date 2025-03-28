class Solution {
public:
    int minimumIndex(vector<int>& nums) {
          
          int value = 0;
          int highFreq = 0;
          unordered_map<int,int>mpp;
          int n = nums.size();
          int count = 0;
          for(int i = 0;i<n;i++){
              mpp[nums[i]]++;
          }

          for(auto it : mpp){
               if(it.second >highFreq){
                   highFreq = it.second;
                   value = it.first;
               }
          }

          for(int i = 0;i<n;i++){
               
               if(value == nums[i]){
                    count++;
                    int size1 = i+1;
                    int size2 = n-(i+1);

                    int count1 = count;
                    int count2 = highFreq-count;
                    if(count1>size1/2 && count2>size2/2){
                           return i;
                    }
               }
          }

          return -1;
    }
};
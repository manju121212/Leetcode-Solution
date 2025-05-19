class Solution {
public:
    string triangleType(vector<int>& nums) {
        
        
        int n = nums.size();
        unordered_map<int,int>mpp1;
        
        for(int i = 0;i<n;i++){
            mpp1[nums[i]]++;
        }
        
        if(mpp1.size() == 1){
            return "equilateral";
        }

          int sum1 = nums[0] +nums[1];
        int sum2 = nums[0] + nums[2];
        int sum3 = nums[1] + nums[2];

        if(sum1 <=nums[2]){
            return "none";
        }
        else if(sum2 <=nums[1]){
            return "none";
        }
        else if(sum3 <=nums[0]){
            return "none";
        }
        


         if(mpp1.size() == 2){
            return "isosceles";
        }

        return "scalene";
       
        
    }
};
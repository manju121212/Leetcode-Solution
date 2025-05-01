class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            int num = nums[i];
            int count = 0;
            while(num!=0){
                count++;
                num = num/10;

            }

            if(count % 2 == 0){
                res++;
            }
        }

        return res;
    }
};
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        

        int evencount = 0;
        int n = arr.size();
        int sum = 0;
        int mod = 1e9+7;
        int count = 0;
        for(int i = 0;i<n;i++){
             sum +=arr[i];
             if(sum % 2 != 0){

                count = (count + evencount+1)%mod;
             }
             else{
                evencount++;
             }
            
        }

        int oddcount = 0;
        sum = 0;
        for(int i = 0;i<n;i++){
            sum += arr[i];
            if(sum % 2 == 0){

                count = (count + oddcount)%mod;
            }
            else{
                oddcount++;
            }
        }

        return count;
    }
};
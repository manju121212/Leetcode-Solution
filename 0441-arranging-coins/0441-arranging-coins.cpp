class Solution {
public:
    int arrangeCoins(int n) {
        long long low = 1;
        long long high = n;
        int res = -1;
        while(low<=high){
            long long mid = low + (high - low)/2;
            long long req_coins_mid = (mid*(mid+1))/2;
            cout<<mid<<"->"<<req_coins_mid<<endl;
            if(req_coins_mid<=n){
                  res = mid;
                  low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return res;
    }
};
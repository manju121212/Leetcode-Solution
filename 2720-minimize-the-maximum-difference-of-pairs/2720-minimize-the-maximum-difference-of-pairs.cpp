class Solution {
public:
bool isPossible(vector<int> arr, int n, int m,int mid){
     int count =0;
   int i = 0 ;

   while(i<n-1){
       if(abs(arr[i] - arr[i+1]) <= mid){
           count++;
           i+=2;
       }
       else{
           i++;
       }
   }

   if(count >= m){
       return true;
   }
   return false;
    
}
    int minimizeMax(vector<int>& arr, int m) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int low=0;
        int ans = 0;
        int high = arr[n-1] - arr[0];
    int mid=low+(high-low)/2;
    while(low<=high){
        if(isPossible(arr,n,m,mid)){
            ans=mid;
               high = mid-1;
           
        }
        else{
            low = mid+1;
        }
        mid=low+(high-low)/2;
    }
    return ans;
    }
};
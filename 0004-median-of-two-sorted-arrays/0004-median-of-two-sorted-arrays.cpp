class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
           int n = nums1.size();
           int m = nums2.size();
           vector<int>ans;


           for(int i = 0;i<n;i++){
                  ans.push_back(nums1[i]);
           }
           for(int i = 0;i<m;i++){
                 ans.push_back(nums2[i]);
           }

           sort(ans.begin(),ans.end());

           int total = n+m;

           if(total%2 ==0){
              int i = total/2;
              cout<<ans[i-1]<<ans[i];
               double a = ((ans[i-1] + ans[i])/2.0);
               return a;
           }
           else{
                 int i = total/2;
               double a = ans[i];
               return a;
           }
    }
};
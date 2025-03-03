class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {

         int i = 0;
         int j = 0;
         int n1 = nums1.size();
           int n2= nums2.size();
         vector<vector<int>>res;
         while(i<n1 && j<n2){
              
              if(nums1[i][0] == nums2[j][0]){
                    res.push_back({nums1[i][0],nums1[i][1] + nums2[j][1]});
                    // res[k][0] = nums1[i][0];
                    // res[k][1] = nums1[i][1] + nums[i][1];
                    // k++;
                    i++;
                    j++;
              }
              else if(nums1[i][0] < nums2[j][0]){
                  res.push_back({nums1[i][0],nums1[i][1] });
                //    res[k][0] = nums1[i][0];
                //    res[k][1] = nums1[i][1];
                //    k++;
                   i++;
                 

              }
              else{
                  res.push_back({nums2[j][0],nums2[j][1]});
                //   res[k][0] = nums1[j][0];
                //    res[k][1] = nums1[j][1];
                //    k++;
                   j++;
              }
         }

         while(i<n1){
             res.push_back({nums1[i][0],nums1[i][1] });
                //   res[k][0] = nums1[i][0];
                //    res[k][1] = nums1[i][1];
                   
                //    k++;
                   i++;
         }

         while(j<n2){
             res.push_back({nums2[j][0], nums2[j][1]});
                //    res[k][0] = nums1[j][0];
                //    res[k][1] = nums1[j][1];
                //    k++;
                   j++;
         }

         return res;  
    }
};
#include<stack>

class Solution {
    private:
    vector<int>next(vector<int> arr,int n){
      stack<int> s;   //tc=o(n) sc=o(n);
      s.push(-1);
      vector<int> ans(n);
      for(int i=n-1;i>=0;i--){
        int curr=arr[i];
        while(s.top()!=-1 && arr[s.top()]>=curr){
            s.pop();
        }
       ans[i]=s.top();
        s.push(i);
    }
   
    return ans;
}
     vector<int>prev(vector<int> arr,int n){
      stack<int> s;   //tc=o(n) sc=o(n);
      s.push(-1);
      vector<int> ans(n);
      for(int i=0;i<n;i++){
        int curr=arr[i];
        while(s.top()!=-1 && arr[s.top()]>=curr){
            s.pop();
        }
       ans[i]=s.top();
        s.push(i);
    }
   
    return ans;
};
    
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int>nextsmallest;
        nextsmallest=next(heights,heights.size());
        vector<int>prevsmallest;
        prevsmallest=prev(heights,heights.size());
        
        int area=INT_MIN;
        for(int i=0;i<heights.size();i++){
            // height is constant so no need to find put direct value as given
            int length=heights[i];
           
            
            if(nextsmallest[i]==-1){
                nextsmallest[i]=heights.size();
            }
             int breath=nextsmallest[i]-prevsmallest[i]-1;
            int totalarea=breath*length;
            
            area=max(area,totalarea);
        }
        return area;
    }
};
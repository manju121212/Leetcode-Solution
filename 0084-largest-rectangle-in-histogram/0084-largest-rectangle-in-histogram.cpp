class Solution {
public:
    vector<int> next(vector<int>& arr,int n){
        
        vector<int>ans(n);
        stack<int> s;
        s.push(-1);
        for(int i=n-1;i>=0;i--){
            
            
            while(s.top()!=-1 && arr[s.top()] >=arr[i])
            {
                s.pop();
            }
            
            ans[i]=s.top();
            s.push(i);
            
        }
        return ans;
    }
      vector<int> prev(vector<int>& arr,int n){
        
        vector<int>ans(n);
        stack<int> s;
        s.push(-1);
        for(int i=0;i<n;i++){
            
            
            while(s.top()!=-1 && arr[s.top()]>=arr[i])
            {
                s.pop();
            }
            
            ans[i]=s.top();
            s.push(i);
            
        }   
          return ans; 
    }
        
    int largestRectangleArea(vector<int>& heights) {
        
        vector<int>nextSmallest;
        vector<int>prevSmallest;
        nextSmallest= next(heights,heights.size());
        prevSmallest= prev(heights,heights.size());
        
        int maxArea= 0;
            
            
        for(int i=0;i<heights.size();i++){
            
            
            int length=heights[i];
            
            
            if(nextSmallest[i]==-1){
                nextSmallest[i]=heights.size();
            }
            
            int width= nextSmallest[i] - 1- prevSmallest[i];
            
            int maxi= length* width;
            
            maxArea=max(maxArea,maxi);
        }
        return maxArea;
        
            
    }
};
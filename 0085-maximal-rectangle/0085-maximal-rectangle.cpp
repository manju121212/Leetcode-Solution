class Solution {
public:
    
    
   vector<int> nextSmallest(vector<int> &arr,int n){
     vector<int>ans(n);
     stack<int>s;
     s.push(-1);
       
     for(int i=n-1;i>=0;i--){

        while(s.top()!=-1 && arr[s.top()] >= arr[i]){
          s.pop();
        
        }
         
        ans[i] = s.top();
        s.push(i); 
     } 
       return ans;
   }
    
   vector<int> prevSmallest(vector<int> &arr,int n){
     vector<int>ans(n);
     stack<int>s;
     s.push(-1);
       
     for(int i=0;i<n;i++){

        while(s.top()!=-1 && arr[s.top()] >= arr[i]){
          s.pop();
        
        }
         
        ans[i] = s.top();
        s.push(i); 
     }
       return ans;
   } 
    
    
  int maxRect(vector<int> &heights){

    int n= heights.size();
    vector<int>prev(n);
    vector<int>next(n);
    
    prev=prevSmallest(heights,n);
    next=nextSmallest(heights,n);
    int maxarea=INT_MIN;    
    for(int i=0;i<n;i++){
            
         int length = heights[i];
          
         if(next[i] ==-1){

            next[i] = n;
         }
        
         int width = next[i]-prev[i] - 1;
         
         int area= length * width;
        
         maxarea= max(area,maxarea);
    
    }
        return maxarea;   
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        vector<int>histogram(matrix[0].size(),0);
        int maxarea=INT_MIN;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<histogram.size();j++){
               if(matrix[i][j] =='1'){
                   histogram[j]++;   
               } 
                else{
                    histogram[j]=0;
                }
            }
            
            maxarea= max(maxarea,maxRect(histogram));
        }
        
        return maxarea;     
        
    }
};
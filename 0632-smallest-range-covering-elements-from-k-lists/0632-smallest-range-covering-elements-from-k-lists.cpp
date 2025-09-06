
class element{
    
    public:
    int data;
    int row;
    int col;
    int arraysize;
    
    
    element(int data,int row,int col,int arraysize){
        this->data=data;
        this->row=row;
        this->col=col;
        this->arraysize=arraysize;
    }
};

class compare{
    
    public:
    bool operator()(element* d1,element* d2){
        return d1->data > d2->data;
    }
};



class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        
        vector<int> ans;
        priority_queue<element*,vector<element*>,compare>pq;
        int mini=INT_MAX,maxi=INT_MIN,range=INT_MAX; 
        
        for(int i=0;i<nums.size();i++){
            element* obj=new element(nums[i][0],i,0,nums[i].size());
            pq.push(obj);
            mini=min(mini,nums[i][0]);
            maxi=max(maxi,nums[i][0]);    
        }
        int low,high;
        while(!pq.empty()){
            element* temp=pq.top();
            pq.pop();
            
            int maybeminimum=temp->data;
            // checking range and updating low and high
            if(range>maxi-maybeminimum){
                mini=maybeminimum;
                range=maxi-mini;
                low=mini;
                high=maxi;
               
            }
            
            // checking if value is within given size of array
            
            if(temp->col==temp->arraysize-1){
                break;
            }
            
            // pushing the value
              int row= temp->row;
              int col=temp->col;
              element* obj=new element(nums[row][col+1],row,col+1,nums[row].size());
              pq.push(obj);   
            
            // updating maxivalue
            maxi=max(maxi,nums[row][col+1]);
          
        }
        ans.push_back(low);
        ans.push_back(high);
        return ans;
    }
};













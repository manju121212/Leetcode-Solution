class Solution {
public:
    void sortColors(vector<int>& arr) {
        //Dutch National Flag Algorithm Approach
        // tc =o(n)  sc=o(1);
        int n = arr.size();
        int start = 0;
        int mid =0;
        int end =n-1;
        while(mid<= end){
        
               
        switch(arr[mid]){
            
            case 0: 
                   swap(arr[start],arr[mid]);
                   start ++;
                   mid++;
                   break;
            case 1:
                  mid++;
                  break;
                  
            case 2: 
                  swap(arr[mid],arr[end]);
                  end--;
                  break;
        }
        
        }
        
        
    }
};
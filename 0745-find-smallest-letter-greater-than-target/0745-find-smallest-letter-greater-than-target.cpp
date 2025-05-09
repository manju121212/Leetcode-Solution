class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        

        int low = 0;
        int high = letters.size()-1;
       
        char res = letters[0];
        while(low<=high){
             int mid =  low + (high - low)/2;
             char ch = letters[mid];
             cout<<mid<<endl;
             if(ch == target){
                  low = mid+1;
             }
             else if(ch > target){
                   res = ch;
                   high = mid-1;
             } 
             else {
                low = mid+1;
             }
        }
        
        
        return res;
    }
};
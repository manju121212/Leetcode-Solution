class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
       int  commoncount = 0;
       int n = A.size();
       vector<int>res(n,0);
       vector<int>count(n+1,0);
       for(int i = 0;i<n;i++){
           count[A[i]]++;
           if(count[A[i]] ==2){
                commoncount++;
           }
           count[B[i]]++;
           if(count[B[i]] == 2){
               commoncount++;
           }

           res[i] = commoncount;
       }

       return res;
    }
};
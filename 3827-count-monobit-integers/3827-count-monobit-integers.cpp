class Solution {
public:
    int countMonobit(int n) {

        int count = 1;
        
        for(int i = 1;i<=n;i++){

              int num = i;
              int prev = -1;
              bool flag = true;
              while(num!=0){
                    int digit = num%2;
                    cout<<digit;
                    if(digit != prev && prev !=-1){
                        flag = false;
                          break;
                    }
                  prev = digit;
                    num = num/2;
                    
              }
              if(flag == true){
                   count++;
              }
              cout<<endl;
        }

        return count;
    }
};
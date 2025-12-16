class Solution {
public:
    int minChanges(string s) {
        
        int n = s.length();
        int c_1= 0;
        int c_0 = 0;
        int min_op = 0;
        for(int i = 0;i<n;i++){

            if(s[i] == '1'){
                c_1++;
            }
            else{
                c_0++;
            }

            if((i+1)%2 == 0){
                int max_c = max(c_1,c_0);
                min_op += 2-max_c;
                c_1 =0;
                c_0 = 0;
            }
        }
        return min_op;
    }
};
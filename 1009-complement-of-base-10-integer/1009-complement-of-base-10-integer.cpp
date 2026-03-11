class Solution {
public:
    int bitwiseComplement(int n) {
        
        string s = "";
        if(n == 0){
             return 1;
        }

        while(n!=0){
            int digit = n%2;
            s += to_string(digit);
            n = n/2;
        }
        cout<<s<<endl;
        reverse(s.begin(),s.end());

        for(int i = 0;i<s.size();i++){
                if(s[i] == '0'){
                     s[i] = '1';
                }
                else{
                    s[i] = '0';
                }
        }
        int j = 0;
        int res = 0;
        for(int i = s.size()-1;i>=0;i--){
              if(s[i] == '1'){
                  res += pow(2,j);

              }
              j++;
        }
        cout<<s;

        return res;
    }
};
class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        
        string s = to_string(n);
        vector<int>res;
        int size = s.size();
        int p = pow(10,size-1);

        for(int i = 0;i<size;i++){

            if(s[i]>='1' && s[i]<='9'){
                  int value = (s[i] - '0')*p;
                  res.push_back(value);
                  p = p/10;
            }
            else{
                 p = p/10;
            }
        }
        return res;
    }
};
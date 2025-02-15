class Solution {
public:
    bool find(int i , string s, vector<string>&res , int target){

        if(i>=s.size()){
            int num = 0;
          
            for(auto it : res){
             
                num += stoi(it);
               

            }
          

            if(num == target){
                return true;
            }
            return false;
        }

        for(int j = i;j<s.size();j++){
            string temp = s.substr(i,j-i+1);
           
            res.push_back(temp);
            if(find(j+1,s,res,target) == true){
                return true;
            }

            res.pop_back();
        }

        return false;
    }
    int punishmentNumber(int n) {
        

        int result = 0;
        for(int i = 1;i<=n;i++){
            int product = i*i;
            string s = to_string(product);
            vector<string>res;

            bool flag = find(0,s,res,i);

            if(flag == true){
                result += product;
            }
        }

        return result;

    }
    };
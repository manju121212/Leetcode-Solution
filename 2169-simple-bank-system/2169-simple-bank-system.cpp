class Bank {
public:
   unordered_map<int,long long>mpp;
   int n;
  
    Bank(vector<long long>& balance) {
         
        

        for(int i = 0;i<balance.size();i++){
              mpp[i+1] = balance[i];
        }

        n = mpp.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
          if(account1>n || account2 >n){
               return false;
          }
          long long amount = mpp[account1];
          if(amount >=money){
              mpp[account1]-=money;
              mpp[account2] +=money;
              return true;
          }

          return false;
    }
    
    bool deposit(int account, long long money) {
           if(account >n){
               return false;
           }
           mpp[account]+=money;
          
           return true;
    }
    
    bool withdraw(int account, long long money) {
        
        long long amount = mpp[account] - money;
        if(amount>=0){
              mpp[account]-=money;
              return true;
        }
        return false;
        
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
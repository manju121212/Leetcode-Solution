class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        

          unordered_map<int,int>mpp;
          int n = hand.size();
          int required = n/groupSize;
          if(n%groupSize != 0){
               return false;
          }

          for(auto it : hand){
              mpp[it]++;
          }

          int i = 0;
          int count = 0;
          sort(hand.begin(),hand.end());
          while(i<n){
                
                if(mpp.find(hand[i]) != mpp.end()){
                      int temp = hand[i];
                      int tempSize = groupSize-1;
                      bool flag = true;
                      mpp[temp]--;
                      if(mpp[temp] == 0){
                         mpp.erase(temp);
                      }

                      while(tempSize>0){
                           if(mpp.find(temp+1) != mpp.end()){
                                 tempSize--;
                                 mpp[temp+1]--;
                                 if(mpp[temp+1] == 0){
                                      mpp.erase(temp+1);
                                 }
                                 temp++;
                                 flag = true;
                           }
                           else{
                              return false;
                              flag = false;
                           }
                      }

                      if(flag == true){
                           count++;
                      }
                }
                else{
                    i++;
                }
          }
          if(count == required){
               return true;
          }

          return false;
    }
};
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        int n = hand.size(); 
        map<int,int> mpp;
        
        if(n % groupSize != 0){
            return false;
        }

        sort(hand.begin(), hand.end());

        for(int i = 0; i < n; i++){
            mpp[hand[i]]++;
        }
        
        for(int i = 0; i < n; i++){
            
            
            if(mpp[hand[i]] == 0)
                continue;

            int len = hand[i];
            int count = 0;

           
            while(count < groupSize){
                
                if(mpp[len] == 0){
                    return false;  
                }

                mpp[len]--;
                len++;
                count++;
            }
        }

        return true;
    }
};

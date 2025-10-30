class Solution {
public:
    bool lemonadeChange(vector<int>& bill) {
        unordered_map<int,int>mpp;
	int n = bill.size();
	for(int i = 0;i<n;i++){
		
		if(bill[i] == 5){
			 mpp[5]++;
		}
		else if(bill[i] == 10){
			  if(mpp.find(5) != mpp.end()){
				    mpp[5]--;
					if(mpp[5]<=0){
						 mpp.erase(5);
					}
					mpp[10]++;
			  }
			  else{
				    return false;
			  }
		}
		else{
            
			if(mpp.find(5) != mpp.end() && mpp.find(10) != mpp.end()){
				mpp[5]--;
				mpp[10]--;
				if(mpp[5]<=0){
						 mpp.erase(5);
				}
				if(mpp[10]<=0){
						 mpp.erase(10);
				}	   

			}
			else if(mpp[5]>=3){
				  mpp[5]-=3;
				  if(mpp[5]<=0){
						 mpp.erase(5);
				}
			}
			else{
				 return false;
			}
		}

	}

	return true;
    }
};
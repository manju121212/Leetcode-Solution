class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int totalsum = 0;
        int n = cardPoints.size();
        int sum = 0;
        
        for(auto it : cardPoints){
              totalsum += it;
        }

        int w_size = n-k;

        for(int i = 0;i<w_size;i++){
              sum +=cardPoints[i];
        }
        int maxi = -1;
        maxi = max(maxi , totalsum-sum);
        int l = 0;
        int r = n-k;
        while(r<n){
             sum-=cardPoints[l++];
             sum +=cardPoints[r++];
             maxi = max(maxi,totalsum - sum);
        }
        return maxi;


    }
};
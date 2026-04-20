class Solution {
public:
    int maxDistance(vector<int>& colors) {
       int i = 0;
       int j = colors.size()-1;
       int maxi = -1;
       while(i<colors.size()){
          if(colors[i] != colors[j]){
             maxi = max(maxi , abs(i-j));
             break;
          }
          else if(colors[i] == colors[j]){
               j--;
          }
          else{
              i++;
          }
       }
        i  = 0;
        j = colors.size()-1;
        while(i<colors.size()){
          if(colors[i] != colors[j]){
             maxi = max(maxi , abs(i-j));
             break;
          }
          else if(colors[i] == colors[j]){
               i++;
          }
          else{
              j--;
          }
       }

       return maxi;
    }
};
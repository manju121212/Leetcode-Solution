class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
      
      
        int n = box.size();
        int m = box[0].size();
        
        int x = 0;
        int y =0;
        int x_1 = m;
        int y_1 = n; 
        vector<vector<char>>res(x_1,vector<char>(y_1));
        for(int i = n-1;i>=0;i--){
             for(int j = 0;j<m;j++){
                  if(x<x_1 && y<y_1){
                       res[x][y] = box[i][j];
                       x++;
                  }
                  else{
                      x = 0;
                      y++;
                      res[x][y] = box[i][j];
                      x++;
                  }
             }
        }

        for(int j = 0;j<y_1;j++){
            
           for(int i = x_1-1;i>=0;i--){
                
                if(res[i][j] == '.'){
                     int stone = -1;
                     for(int k = i-1;k>=0;k--){
                          if(res[k][j] == '*'){
                            break;
                          }
                          else if(res[k][j] == '#'){
                              stone = k;
                              break;
                          }
                     }

                     if(stone != -1){
                         res[i][j] = '#';
                         res[stone][j] = '.';
                     }
                }
           }
           
        }
        return res;



    }
};
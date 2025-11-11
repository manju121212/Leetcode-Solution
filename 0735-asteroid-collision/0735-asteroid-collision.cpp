class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        
        stack<int>st;
        vector<int>ans;
        for(int &it : asteroids){
            
            while(!st.empty() && it <0 && st.top()>0){
                
                int sum = st.top() +it;
                if(sum >0){
                        it=0;
                }
                else if(sum <0){
                         
                    st.pop();
                }
                else if(sum==0){
                      st.pop();
                      it=0;
                }
            }
            
            if(it!=0){
                  st.push(it);
            }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
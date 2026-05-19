class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int,int>vis;

        for(auto it : nums1){
            vis[it]++;
        }
        int mini = 1e9;
        bool flag = false;
        for(auto it : nums2){
              if(vis[it] != 0){
                if(mini > it){}
                   mini = min(mini,it);
                   flag = true;
              }
        }

        return mini == 1e9 && flag ==false ? -1 : mini;
    }
};
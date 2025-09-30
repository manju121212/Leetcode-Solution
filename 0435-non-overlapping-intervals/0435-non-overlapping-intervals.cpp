class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
            if(a[0] < b[0]){
                return true;
            }
           else if(a[0] == b[0]){
           return a[1] <b[1];
        }
         return false;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end(),cmp);
        
        int count =0;
        stack<pair<int,int>>st;
        st.push({intervals[0][0],intervals[0][1]});
        int n = intervals.size();
        for(int i =1 ;i<n;i++){
            int u = intervals[i][0];
            int v = intervals[i][1];
            if(u < st.top().second){
             
                count++;
                st.top().second = min(v,st.top().second);
            }
            else{
               st.push({u,v});
            }
}
       
        return count;
    }
};
class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        
        unordered_map<int,set<int>>mppx,mppy;

        for(int i = 0;i<buildings.size();i++){
                int u = buildings[i][0];
                int v = buildings[i][1];
                mppx[u].insert(v);
                mppy[v].insert(u);

        }
        int count = 0;
        for(int i = 0;i<buildings.size();i++){
            int x = buildings[i][0];
            int y = buildings[i][1];

            auto left = mppy[y].lower_bound(x);
            auto right = mppy[y].upper_bound(x);

            auto down = mppx[x].lower_bound(y);
            auto up = mppx[x].upper_bound(y);

            if(left != mppy[y].begin() && right != mppy[y].end() && up != mppx[x].end() && down != mppx[x].begin() ){
                count++;
            }

        }

        return count;
    }
};
class Solution {
public:
    int dp[200][200];
    int bfs(int source,int target,vector<pair<int,int>>adj[],vector<int>&dist)
    {
        if(dp[source][target]!=-1)
        {
            return dp[source][target];
        }
        dist[source]=0;
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,source});
        while(!pq.empty())
        {
            int cost=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(node==target)
            {
                return dp[source][target]=cost;
            }
            for(auto it:adj[node])
            {
                if(dist[it.first]>cost+it.second)
                {
                    dist[it.first]=cost+it.second;
                    pq.push({cost+it.second,it.first});
                }
            }
        }
        return dp[source][target]=-1;
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n=original.size();
memset(dp, -1, sizeof(dp));

        vector<pair<int,int>>adj[26+1];
        for(int i=0;i<n;i++)
        {
            adj[original[i]-'a'].push_back({changed[i]-'a',cost[i]});
        }
        long long  finals=0;
        for(int i=0;i<source.size();i++)
        {
            if(source[i]==target[i])
            {
                continue;
            }
            else
            {
                vector<int>dist(26,1e7);
                
                long long  ans=bfs(source[i]-'a',target[i]-'a',adj,dist);
                if(ans==-1)
                {
                    return -1;
                }
                finals+=ans;
                
            }
        }
        return finals;
        
    }
};

 

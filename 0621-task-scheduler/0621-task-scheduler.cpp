class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mpp;
        int count = 0;
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> vis;

        for (char task : tasks) {
            mpp[task]++;
        }

        for (auto it : mpp) {
            pq.push({it.second, it.first});
        }

        int i = 0;
        while (!pq.empty()) {
            bool done = false;
            vector<pair<int, char>> temp;

            while (!pq.empty()) {
                char ch = pq.top().second;
                int freq = pq.top().first;
                pq.pop();

                if (vis.find(ch) == vis.end() || i - vis[ch] > n) {
                    // Task can be scheduled
                    freq--;
                    vis[ch] = i;
                    if (freq > 0) {
                        temp.push_back({freq, ch});
                    }
                    done = true;
                    break;
                } else {
                    // Cannot schedule now
                    temp.push_back({freq, ch});
                }
            }

            // Push back all remaining tasks into pq
            for (auto p : temp) {
                pq.push(p);
            }

            // If a task was done, count it
            // If not, CPU is idle for this interval
            count++;
            i++;
        }

        return count;
    }
};

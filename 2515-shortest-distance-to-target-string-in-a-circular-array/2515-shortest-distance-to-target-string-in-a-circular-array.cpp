class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int index = startIndex;
        int mini = 1e9;
        int n = words.size();

        if (words[index] == target) {
            return 0;
        }

        int count1 = 0, count2 = 0;

        // left
        while (true) {
            index = (index - 1 + n) % n;
            count1++;

            if (index == startIndex) break;

            if (words[index] == target) {
                mini = min(mini, count1);
                break;
            }
        }

        // right
        index = startIndex;
        while (true) {
            index = (index + 1) % n;
            count2++;

            if (index == startIndex) break;

            if (words[index] == target) {
                mini = min(mini, count2);
                break;
            }
        }

        return mini == 1e9 ? -1 : mini;
    }
};
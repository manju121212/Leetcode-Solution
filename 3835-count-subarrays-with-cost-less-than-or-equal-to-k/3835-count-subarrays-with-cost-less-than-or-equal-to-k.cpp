class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {

        int n = nums.size();

        deque<int> maxD;  
        deque<int> minD;   

        long long totalCount = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {

           
            while (!maxD.empty() && nums[maxD.back()] <= nums[right])
                maxD.pop_back();
            maxD.push_back(right);

           
            while (!minD.empty() && nums[minD.back()] >= nums[right])
                minD.pop_back();
            minD.push_back(right);

          
            while (!maxD.empty() && !minD.empty() &&
                   (long long)(nums[maxD.front()] - nums[minD.front()])
                   * (right - left + 1) > k) {

                if (maxD.front() == left) maxD.pop_front();
                if (minD.front() == left) minD.pop_front();
                left++;
            }

           
            totalCount += (right - left + 1);
        }

        return totalCount;
    }
};
class Solution {
public:
    
long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
    unordered_map<int, long long> prefixCount;
    prefixCount[0] = 1; // base case: prefix sum = 0
    
    long long ans = 0;
    int count = 0; // number of elements where nums[i] % modulo == k so far
    
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] % modulo == k) {
            count++;  // we found a number that satisfies the condition
        }
        
        // We want earlier prefix count mod such that:
        // (current_count - earlier_count) % modulo == k
        int need = (count - k + modulo) % modulo;
        
        ans += prefixCount[need]; // add how many such earlier prefixes exist
        
        // Record this prefix count modulo
        prefixCount[count % modulo]++;
    }
    
    return ans;
}
};
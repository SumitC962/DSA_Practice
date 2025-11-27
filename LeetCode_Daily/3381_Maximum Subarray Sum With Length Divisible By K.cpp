class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long prefix = 0;
        long long ans = LLONG_MIN;
        vector<long long> minPrefix(k, LLONG_MAX);

        minPrefix[0] = 0; 

        for (int i = 0; i < nums.size(); i++) {
            prefix += nums[i];
            int rem = (i + 1) % k;

            if (minPrefix[rem] != LLONG_MAX) {
                ans = max(ans, prefix - minPrefix[rem]);
            }

            minPrefix[rem] = min(minPrefix[rem], prefix);
        }

        return ans;
    }
};

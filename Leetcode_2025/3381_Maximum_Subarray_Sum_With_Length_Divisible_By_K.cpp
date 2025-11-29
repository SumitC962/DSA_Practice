#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long prefix = 0;
        long long ans = LLONG_MIN;
        vector<long long> minPrefix(k, LLONG_MAX);

        minPrefix[0] = 0; // prefix before starting

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

int main() {
    vector<int> nums = {1, -2, 3, 4, -1, 2};
    int k = 3;

    Solution s;
    cout << s.maxSubarraySum(nums, k) << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long totalSum = 0;
        for (int x : nums) totalSum += x;
        int need = totalSum % p;
        if (need == 0) return 0;

        unordered_map<int, int> mp;
        mp[0] = -1;

        long long prefix = 0;
        int ans = nums.size();

        for (int i = 0; i < (int)nums.size(); ++i) {
            prefix = (prefix + nums[i]) % p;
            int target = (prefix - need + p) % p;

            if (mp.count(target)) {
                ans = min(ans, i - mp[target]);
            }

            mp[prefix] = i;
        }

        return ans == (int)nums.size() ? -1 : ans;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums = {3, 1, 4, 2};
    int p = 6;
    Solution sol;
    cout << sol.minSubarray(nums, p) << '\n';
    return 0;
}

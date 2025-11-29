#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
            sum += nums[i];
        }
        return sum % k;
    }
};

int main() {
    vector<int> nums = {3, 1, 4, 2};
    int k = 6;
    Solution s;
    cout << "Result: " << s.minOperations(nums, k) << '\n';
    return 0;
}
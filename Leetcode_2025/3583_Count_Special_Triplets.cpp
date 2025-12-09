class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();

        unordered_map<long long, long long> rightFreq, leftFreq;
        for (long long x : nums) rightFreq[x]++;
        long long ans = 0;

        for (int j = 0; j < n; j++) {
            long long x = nums[j];
            rightFreq[x]--;
            long long target = 2LL * x;
            long long leftCnt = leftFreq[target];
            long long rightCnt = rightFreq[target];
            ans = (ans + (leftCnt * rightCnt) % MOD) % MOD;
            leftFreq[x]++;
        }

        return ans;
    }
};

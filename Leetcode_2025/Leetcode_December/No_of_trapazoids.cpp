#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const long long mod = 1000000007;

        unordered_map<int, long long> freq;
        for (auto &p : points) {
            freq[p[1]]++; // count by y-coordinate
        }

        long long sum = 0;
        long long ans = 0;

        for (auto &it : freq) {
            long long Cy = it.second;
            long long Vy = Cy * (Cy - 1) / 2 % mod;

            ans = (ans + sum * Vy) % mod;
            sum = (sum + Vy) % mod;
        }

        return (int)ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> points(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> points[i][0] >> points[i][1];
    }

    Solution sol;
    cout << sol.countTrapezoids(points) << "\n";

    return 0;
}

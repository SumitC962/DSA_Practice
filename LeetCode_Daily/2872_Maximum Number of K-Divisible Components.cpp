class Solution {
public:
    long long k;
    vector<vector<int>> adj;
    vector<long long> vals;
    int cuts = 0;

    long long dfs(int u, int p) {
        long long sum = vals[u];

        for (int v : adj[u]) {
            if (v == p) continue;

            long long sub = dfs(v, u);
            if (sub % k == 0) {
                cuts++;          
            } else {
                sum += sub;      
            }
        }
        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int K) {
        k = K;
        adj.assign(n, {});
        vals.assign(values.begin(), values.end());
        cuts = 0;

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, -1);
        return cuts + 1;   
    }
};

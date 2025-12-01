// File: max_run_time.cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long totalEnergy = 0;
        for (int b : batteries) 
            totalEnergy += b;

        sort(batteries.begin(), batteries.end());

        for (int i = batteries.size() - 1; i >= 0; i--) {
            if (batteries[i] > totalEnergy / n) {
                totalEnergy -= batteries[i];
                n--;
            } else {
                break;
            }
        }

        return totalEnergy / n;
    }
};

int main() {
    int n, m;
    cout<<"enter number of computers and batteries:"<<endl;
    cin >> n >> m;
    vector<int> batteries(m);
    cout<<"enter battery capacities:"<<endl;
    for (int i = 0; i < m; i++) 
    cin >> batteries[i];

    Solution sol;
    cout << sol.maxRunTime(n, batteries) << endl;
}

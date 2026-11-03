#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <numeric>
#include <iomanip>
#include <cassert>
#include <cstring>

#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<int> vals = b;
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    vector<int> id(n);

    for (int i = 0; i < n; i++) {
        id[i] = lower_bound(all(vals), b[i])
                - vals.begin();
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));

    int ans = 1;

    for (int i = 0; i < n; i++) {
        vector<int> best(vals.size(), 0);

        for (int k = 0; k < i; k++) {
            best[id[k]] = max(best[id[k]], dp[k][i]);
        }

        for (int j = i + 1; j < n; j++) {
            dp[i][j] = max(2, best[id[j]] + 1);
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << '\n';

    return 0;
}
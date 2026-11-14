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

const int MOD = 1e9 + 7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<ll>> a(n + 2, vector<ll>(m + 2, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }

    vector<vector<ll>> dp1(n + 2, vector<ll>(m + 2, 0)); // (1,1) в (i,j)
    vector<vector<ll>> dp2(n + 2, vector<ll>(m + 2, 0)); // (n,m) в (i,j)
    vector<vector<ll>> dp3(n + 2, vector<ll>(m + 2, 0)); // (n,1) в (i,j)
    vector<vector<ll>> dp4(n + 2, vector<ll>(m + 2, 0)); // (1,m) в (i,j)

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            dp1[i][j] = a[i][j] + max(dp1[i - 1][j], dp1[i][j - 1]);

    for (int i = n; i >= 1; --i)
        for (int j = m; j >= 1; --j)
            dp2[i][j] = a[i][j] + max(dp2[i + 1][j], dp2[i][j + 1]);

    for (int i = n; i >= 1; --i)
        for (int j = 1; j <= m; ++j)
            dp3[i][j] = a[i][j] + max(dp3[i + 1][j], dp3[i][j - 1]);

    for (int i = 1; i <= n; ++i)
        for (int j = m; j >= 1; --j)
            dp4[i][j] = a[i][j] + max(dp4[i - 1][j], dp4[i][j + 1]);

    ll ans = 0;
    for (int i = 2; i < n; ++i) {
        for (int j = 2; j < m; ++j) {
            ll case1 = dp1[i - 1][j] + dp2[i + 1][j] + dp3[i][j - 1] + dp4[i][j + 1];
            ll case2 = dp1[i][j - 1] + dp2[i][j + 1] + dp3[i + 1][j] + dp4[i - 1][j];
            ans = max({ans, case1, case2});
        }
    }

    cout << ans << '\n';
    return 0;
}
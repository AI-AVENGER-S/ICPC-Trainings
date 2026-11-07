#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <numeric>
#include <iomanip>
#include <cassert>
#include <cstring>

#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long;

const int MOD = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> dp(m + 3, 0);
    dp[m + 2] = 1;

    ll ans = 0;

    for (int len = 2; len <= n; len++) {
        vector<ll> pref(m + 3, 0);

        for (int i = 1; i <= m + 2; i++) {
            pref[i] = (pref[i - 1] + dp[i]) % MOD;
        }

        vector<ll> ndp(m + 3, 0);

        for (int v = 2; v <= m + 2; v++) {
            int r = min(2 * v - 1, m + 2);

            ndp[v] = (pref[r] - pref[v - 1] + MOD) % MOD;
        }

        ans = (ans + ndp[2]) % MOD;

        dp = ndp;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

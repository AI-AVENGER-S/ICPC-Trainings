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

int n, p;
vector<int> a;
unordered_map<int, ll> memoisation;

ll dp(int x) {
    if (x <= 1) return x;

    if (memoisation.count(x)) {
        return memoisation[x];
    }

    ll ans = x;

    for (int c = 2; c <= n && c < (ll)2 * x; c++) {
        int q = x / c;
        int r = x % c;

        if (q > 0) {
            ans = min(ans, dp(q) + a[c] + r);
        }

        if (r > 0) {
            ans = min(ans, dp(q + 1) + a[c] + c - r);
        }
    }

    return memoisation[x] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> p;

    a.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    cout << dp(p) << '\n';
}
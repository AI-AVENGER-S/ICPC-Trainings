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

    int n, l, r, Ql, Qr;
    cin >> n >> l >> r >> Ql >> Qr;

    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    vector<int> pref(n + 1);
    pref[0] = 0;
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + w[i - 1];
    }

    ll ans = LLONG_MAX;
    for (int i = 0; i <= n; i++) {
        ll cur = pref[i] * l + (pref[n] - pref[i]) * r;
        if (i > n - i) cur += (i - (n - i) - 1) * Ql;
        if (i < n - i) cur += ((n - i) - i - 1) * Qr;
        
        ans = min(ans, cur);
    }

    cout << ans << '\n';

    return 0;
}
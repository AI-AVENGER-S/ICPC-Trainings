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


int solve(){
    int n;
    cin >> n;

    vector<ll> a(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<ll> d(n + 1, 0);

    ll M = 0;

    for (int i = 1; i < n; ++i) {
        d[i] = abs(a[i] - a[i + 1]);
        M = max(M, d[i]);
    }

    vector<ll> pref(n + 1, 0);
    vector<ll> suff(n + 2, 0);

    for (int i = 1; i < n; ++i) {
        pref[i] = max(pref[i - 1], d[i]);
    }

    for (int i = n - 1; i >= 1; --i) {
        suff[i] = max(suff[i + 1], d[i]);
    }

    vector<int> pos;

    for (int i = 1; i < n; ++i) {
        if (d[i] == M) {
            pos.push_back(i);
        }
    }

    ll ans = M;

    if (pos.size() > 2) {
        cout << ans << '\n';
        return 0;
    }

    if (pos.size() == 2) {
        int p = pos[0];
        int q = pos[1];

        ll inside = 0;

        for (int i = p + 1; i < q; ++i) {
            inside = max(inside, d[i]);
        }

        ll cur = max({
            pref[p - 1],
            suff[q + 1],
            2 * inside,
            abs(a[p] - 2 * a[q]),
            abs(2 * a[p + 1] - a[q + 1])
        });

        ans = min(ans, cur);
    }
    else {
        int p = pos[0];
        ll inside = 0;

        for (int r = p + 1; r <= n; ++r) {

            if (r > p + 1) {
                inside = max(inside, d[r - 1]);
            }

            ll cur = max({
                pref[p - 1],
                suff[r + 1],
                2 * inside,
                abs(a[p] - 2 * a[r])
            });

            if (r < n) {
                cur = max(cur, abs(2 * a[p + 1] - a[r + 1]));
            }

            ans = min(ans, cur);
        }

        inside = 0;

        for (int l = p; l >= 1; --l) {

            if (l < p) {
                inside = max(inside, d[l]);
            }

            ll cur = max({
                (l >= 2 ? pref[l - 2] : 0LL),
                suff[p + 1],
                2 * inside,
                abs(2 * a[l] - a[p + 1])
            });

            if (l > 1) {
                cur = max(cur, abs(a[l - 1] - 2 * a[p]));
            }

            ans = min(ans, cur);
        }
    }

    cout << ans << '\n';
    return 0;
}
    


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}
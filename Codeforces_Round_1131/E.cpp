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


void solve() {
    int n;
    cin >> n;

    vector<ll> odd, even;

    ll ans = 0;

    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;

        ans += x;

        if (!(i & 1))
            odd.push_back(x);
        else
            even.push_back(x);
    }

    sort(all(odd));
    sort(all(even));

    for (int i = 0; i < even.size(); ++i) {
        ll sum = odd[i] + even[i];

        if (sum < 0) {
            ans -= 2 * sum;
        }
        else {
            break;
        }
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

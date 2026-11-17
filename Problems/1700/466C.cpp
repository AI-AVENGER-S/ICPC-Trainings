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

    int n;
    cin >> n;

    vector<ll> a(n);
    ll total = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total += a[i];
    }

    if (total % 3 != 0) {
        cout << 0 << '\n';
        return 0;
    }

    ll target = total / 3;

    vector<ll> cnt(n, 0);

    ll sum = 0;

    for (int i = n - 1; i >= 0; --i) {
        sum += a[i];

        if (sum == target) {
            cnt[i] = 1;
        }
    }

    for (int i = n - 2; i >= 0; --i) {
        cnt[i] += cnt[i + 1];
    }

    ll ans = 0;
    sum = 0;

    for (int i = 0; i + 2 < n; ++i) {
        sum += a[i];

        if (sum == target) {
            ans += cnt[i + 2];
        }
    }

    cout << ans << '\n';

    return 0;
}

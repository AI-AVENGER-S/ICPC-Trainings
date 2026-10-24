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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> diff(n + 1, 0);

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;

        ++diff[l - 1];
        --diff[r];
    }

    vector<int> count(n);
    int cur = 0;

    for (int i = 0; i < n; ++i) {
        cur += diff[i];
        count[i] = cur;
    }

    sort(all(a));
    sort(all(count));

    ll ans = 0;

    for (int i = 0; i < n; ++i) {
        ans += 1LL * a[i] * count[i];
    }

    cout << ans << '\n';

    return 0;
}
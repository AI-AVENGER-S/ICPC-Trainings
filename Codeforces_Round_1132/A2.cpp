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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(all(a), greater<int>());

    ll sum_x = 0;
    ll sum_y = 0;

    for (int i = 0; i < n; ++i) {
        ll val = 1LL << a[i];
        if (sum_x <= sum_y) {
            sum_x += val;
        } else {
            sum_y += val;
        }
    }

    ll max_area = sum_x * sum_y;
    cout << max_area << "\n";
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
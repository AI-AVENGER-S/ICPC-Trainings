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
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(all(a));

    ll max_val = a[n - 1];
    int c = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == max_val) {
            c++;
        } else {
            break;
        }
    }

    if (k < c) {
        cout << "NO" << '\n';
        return;
    }

    cout << "YES" << '\n';

    for (int i = n - k; i < n; ++i) {
        cout << a[i] << " ";
    }

    for (int i = n - k - 1; i >= 0; --i) {
        cout << a[i] << " ";
    }
    cout << "\n";
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
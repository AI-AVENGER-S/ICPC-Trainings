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


int solve() {
    int n;
    cin >> n;

    vector<int> a(n);

    ll sum = 0;
    for (int i = 0; i < n; ++i) { 
        cin >> a[i]; 
        sum += a[i];
    }

    if (sum == n) {
        cout << "-1" << '\n';
        return 0;
    }

    int cnt_ones_in = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (a[i] == 1) ++cnt_ones_in;
    }

    if (cnt_ones_in == n - 2) {
        cout << sum - 1 - (n - 2) << '\n';
        return 0;
    }

    cout << sum - 1 << '\n';
    return 0;
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

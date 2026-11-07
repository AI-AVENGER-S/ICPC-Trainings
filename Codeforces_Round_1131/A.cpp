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

int solve() {
    int l, r;
    cin >> l >> r;

    if (l > 0 || r < 0) {
        cout << r - l << "\n";
        return 0;
    }

    if (-l == r) {
        cout << 0 << "\n";
        return 0;
    }

    int m = min(-l, r);
    cout << r - l + 1 - 2 * m - 2 << "\n";

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
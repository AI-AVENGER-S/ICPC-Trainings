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


ll lcm(ll a, ll b) {
    return (a / std::gcd(a, b)) * b;
}

ll lcm3(ll a, ll b, ll c) {
    return lcm(lcm(a, b), c);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    if (n == 1) { cout << 1 << "\n"; return 0; }
    if (n == 2) { cout << 2 << "\n"; return 0; }
    if (n == 3) { cout << 6 << "\n"; return 0; }

    ll start = max(1, n - 50);
    ll ans = 0;

    for (ll i = n; i >= start; --i) {
        for (ll j = n; j >= start; --j) {
            for (ll k = n; k >= start; --k) {
                ans = max(ans, lcm3(i, j, k));
            }
        }
    }

    cout << ans << "\n";

    return 0;
}


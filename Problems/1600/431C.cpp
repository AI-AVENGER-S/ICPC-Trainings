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

    int n, k, d;
    cin >> n >> k >> d;

    vector<ll> dp_d(n + 1, 0);
    dp_d[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = max(0, i - k); j < i; j++) {
            if (i - j < d) {
                dp_d[i] += dp_d[j];
                dp_d[i] %= MOD;
            }
        }
    }

    vector<ll> dp_all(n + 1, 0);
    dp_all[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = max(0, i - k); j < i; j++) {
            dp_all[i] += dp_all[j];
            dp_all[i] %= MOD;
        }
    }

    cout << (dp_all[n] - dp_d[n] + MOD) % MOD << '\n';
    return 0;
}
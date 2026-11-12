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
    ll k;
    cin >> n >> k;

    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(all(a));

    int l = 0, r = 0;

    int best_len = 0;
    int best_value = a[0];

    while (r < n) {
        if (a[l] == a[r]) {
            if (best_len < r - l + 1) {
                best_len = r - l + 1;
                best_value = a[r];
            }

            ++r;
            continue;
        }

        ll need = 1LL * (a[r] - a[r - 1]) * (r - l);

        if (k < need) {
            k += 1LL * (a[r - 1] - a[l]);
            ++l;
            continue;
        }

        k -= need;

        if (best_len < r - l + 1) {
            best_len = r - l + 1;
            best_value = a[r];
        }

        ++r;
    }

    cout << best_len << ' ' << best_value << '\n';

    return 0;
}
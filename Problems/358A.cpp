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
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ll> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    bool intersected = false;

    for (int i = 0; i < n - 1; ++i) {
        ll l1 = min(x[i], x[i + 1]);
        ll r1 = max(x[i], x[i + 1]);

        for (int j = i + 1; j < n - 1; ++j) {
            ll l2 = min(x[j], x[j + 1]);
            ll r2 = max(x[j], x[j + 1]);

            if ((l1 < l2 && l2 < r1 && r1 < r2) || (l2 < l1 && l1 < r2 && r2 < r1)) {
                intersected = true;
                break;
            }
        }
        if (intersected) break;
    }

    if (intersected) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }

    return 0;

}
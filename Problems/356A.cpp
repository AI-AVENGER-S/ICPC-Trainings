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

    int n, m;
    cin >> n >> m;

    set<int> alive;
    for (int i = 1; i <= n; i++) {
        alive.insert(i);
    }

    vector<int> ans(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int l, r, x;
        cin >> l >> r >> x;

        auto it = alive.lower_bound(l);

        while (it != alive.end() && *it <= r) {
            int v = *it;

            if (v == x) {
                ++it;
            } else {
                ans[v] = x;
                it = alive.erase(it);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}



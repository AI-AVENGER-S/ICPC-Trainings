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
    int n;
    cin >> n;

    vector<int> a(n);
    int mx = 1;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    vector<int> min_del(mx + 1);

    for (int i = 2; i <= mx; i++) {
        if (min_del[i] == 0) {
            for (int j = i; j <= mx; j += i) {
                if (min_del[j] == 0) {
                    min_del[j] = i;
                }
            }
        }
    }

    vector<int> best(mx + 1, 0);

    int ans = 1;

    for (int x : a) {
        int dp = 1;
        int y = x;

        while (y > 1) {
            int p = min_del[y];
            dp = max(dp, best[p] + 1);

            while (y % p == 0) {
                y /= p;
            }
        }

        y = x;

        while (y > 1) {
            int p = min_del[y];
            best[p] = max(best[p], dp);

            while (y % p == 0) {
                y /= p;
            }
        }

        ans = max(ans, dp);
    }

    cout << ans << '\n';
}

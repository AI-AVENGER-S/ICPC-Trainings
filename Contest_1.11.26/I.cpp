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

    ll n;
    cin >> n;

    for (ll mid = n + 1; mid <= n * n + 2 * n + 1; mid++) {
        ll D = mid * mid - 4 * mid * n;

        if (D < 0) continue;

        ll sq = sqrtl(D);

        if (sq * sq != D) continue;
        if ((mid + sq) % 2 != 0) continue;

        ll a = (mid + sq) / 2;
        ll b = (mid - sq) / 2;

        if (a != b && a > 0 && b > 0) {
            cout << b << ' ' << a << '\n';
            return 0;
        }
    }

    return 0;
}
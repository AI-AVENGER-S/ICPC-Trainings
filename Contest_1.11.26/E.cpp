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


void solve() {
    long double a, b, c;
    cin >> a >> b >> c;

    long double A = a / 3;
    long double B = b / 3;
    long double C = c / 10;

    long double x = max({A, B, C});

    long double ans_a = (A == x ? 0 : 3 * (x - A));
    long double ans_b = (B == x ? 0 : 3 * (x - B));
    long double ans_c = (C == x ? 0 : 10 * (x - C));

    cout << fixed << setprecision(10)
         << ans_a << ' ' << ans_b << ' ' << ans_c << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}

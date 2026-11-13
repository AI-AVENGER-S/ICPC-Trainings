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

    int m, n;
    cin >> m >> n;


    double prev_dp = pow(1.0 / m, n);
    double ans = prev_dp;

    for (int i = 2; i <= m; ++i) {
        double curr_dp = pow(static_cast<double>(i) / m, n);
        ans += i * (curr_dp - prev_dp);
        prev_dp = curr_dp;
    }

    cout << fixed << setprecision(7) << ans << '\n';
    return 0;   
}
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

const int MOD = 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int v;
    cin >> v;

    vector<int> a(10);

    int mn = pow(10, 6);
    for(int i = 1; i <= 9; ++i) {
        cin >> a[i];
        mn = min(mn, a[i]);
    }
    
    int len = v / mn;
    int extra = v % mn;

    if (!len) {
        cout << -1 << '\n';
        return 0;
    }

    string ans;

    for (int pos = 0; pos < len; ++pos) {
        for (int d = 9; d >= 1; --d) {
            if (a[d] - mn <= extra) {
                ans += char('0' + d);
                extra -= a[d] - mn;
                break;
            }
        }
    }

    cout << ans << '\n';
    return 0;

}
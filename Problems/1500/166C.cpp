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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(all(a));
    
    int less = lower_bound(all(a), x) - a.begin(); 
    int less_or_equal = upper_bound(all(a), x) - a.begin();

    int ans = max({0, 2 * less - n + 1, n - 2 * less_or_equal});

    cout << ans << '\n';

    return 0;
}
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

int solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i){
        int cur = 0;
        for (int j = 0; j < n; ++j){
            if (a[j] % a[i] == 0) ++cur;

            ans = max(ans, cur);
        }
    }
    cout << n - ans << '\n';
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
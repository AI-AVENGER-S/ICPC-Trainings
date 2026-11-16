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


void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    int maxi = -1;
    for (auto& x: a) {
        cin >> x;
        maxi = max(maxi, x);
    }

    vector<int> cnt(maxi + 1, 0);
    int max_k = 0;
    for (auto& x: a) {
        ++cnt[x];
        max_k = max(max_k, cnt[x]);
    }

    sort(all(a));

    int r = max((n + k - 1) / k, max_k);


    vector<vector<int>> ans(r);

    for (int i = 0; i < n; ++i){
        ans[i % r].push_back(a[i]);
    }
    

    cout << r << '\n';
    for (int i = 0; i < r; ++i) {
        cout << ans[i].size() << ' ';
        for (int el : ans[i]) {
            cout << el << ' ';
        }
        cout << '\n';
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int _;
    cin >> _;
    while (_--) {
        solve();
    }
    
    return 0;
}

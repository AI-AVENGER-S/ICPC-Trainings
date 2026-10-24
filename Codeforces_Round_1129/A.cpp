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
    int n, k;
    cin >> n >> k;
    
    vector<int> count(n + 2, 0);
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;

        if (val <= n + 1) {
            ++count[val];
        }
    }
    
    int pool = 0;
    int mex = 0;
    
    while (true) {
        if (count[mex] < 1) {
            break;
        }
        
        pool += count[mex];
        
        if (pool < k) {
            break;
        }
        
        pool -= k;
        ++mex;
    }
    
    cout << mex << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}

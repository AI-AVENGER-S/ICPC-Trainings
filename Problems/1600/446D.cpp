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

    int n;
    cin >> n;

    vector<int> a(n), l(n, 1), r(n, 1);

    for (int &x : a) cin >> x;

    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]){
            l[i] = l[i - 1] + 1;
        }
    }
    

    for (int i = n - 2; i >= 0; i--)
        if (a[i] < a[i + 1]) 
            r[i] = r[i + 1] + 1;

    
    int ans = max(l[n - 1], r[0]);

    if (n > 1) {
        ans = max(ans, l[n - 2] + 1);
        ans = max(ans, r[1] + 1);
    }

    for (int i = 1; i < n - 1; i++) {
        if (a[i - 1] + 1 < a[i + 1])
            ans = max(ans, l[i - 1] + 1 + r[i + 1]);
        else
            ans = max(ans, max(l[i - 1], r[i + 1]) + 1);
    }

    cout << min(ans, n) << '\n';
}
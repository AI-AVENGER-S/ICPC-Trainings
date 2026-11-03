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

    ll l, r;
    cin >> l >> r;

    int k;
    cin >> k;
    
    ll num = 1;
    vector<ll> ans;

    while (true) {
        if (num > r) break;
        if (num >= l) ans.push_back(num);
        if (num > r / k) break; 
        num *= k;
    }

    if (ans.empty()) {
        cout << -1;
    }

    for (ll x : ans) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}
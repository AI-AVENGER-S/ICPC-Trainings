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

void solve(){
    int n;
    cin >> n;
    
    ll ans = 0; 

    string s;
    cin >> s;
    
    vector<int> pref_sums(n + 1, -1);
    unordered_map<int, int> cnt;
    cnt[-1] = 1;

    for (int i = 1; i < n + 1; ++i){
        pref_sums[i] = (s[i - 1] - '0') + pref_sums[i - 1] - 1;
        ans += cnt[pref_sums[i]];
        ++cnt[pref_sums[i]];
    }
    cout << ans << '\n';
    return;
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
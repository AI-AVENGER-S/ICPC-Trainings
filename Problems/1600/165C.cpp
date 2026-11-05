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

    int k;
    cin >> k;

    string s;
    cin >> s;

    int cur_ones = 0;
    vector<ll> cnt(s.size() + 1, 0);
    cnt[0] = 1;
    ll ans = 0;

    for (char c : s) {
        if (c == '1') cur_ones++;
        if (cur_ones >= k) ans += cnt[cur_ones - k];
        cnt[cur_ones]++;
    }

    cout << ans << '\n';
    return 0;
}
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

    vector<int> a(n);

    ll sum = 0;
    int max_el = -1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        max_el = max(max_el, a[i]);
    }

    cout << max((ll)max_el, (sum + (n - 1) - 1) / (n - 1)) << '\n';
    return 0;
}
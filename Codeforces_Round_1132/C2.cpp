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

void solve() {
    int a, b;
    cin >> a >> b;

    if (a == b) {
        cout << 0 << "\n";
        return;
    }


    int diff = b - a;
    vector<int> ans;

    while (diff > 0) {
        int num = diff;

        while (num > 0 && gcd(a, num) != 1) {
            --num;
        }

        ans.push_back(num);
        a += num;
        diff = b - a;
    }

    cout << ans.size() << "\n";
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << "\n";

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
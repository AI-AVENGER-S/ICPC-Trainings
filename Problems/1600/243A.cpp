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

    vector<int> cur;
    vector<bool> used(1 << 20, false);

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        vector<int> nxt;

        nxt.push_back(x);

        for (int v : cur) {
            nxt.push_back(v | x);
        }

        sort(all(nxt));
        nxt.erase(unique(all(nxt)), nxt.end());

        for (int v : nxt) {
            if (!used[v]) {
                used[v] = true;
                ans++;
            }
        }

        cur = nxt;
    }

    cout << ans << '\n';
    return 0;
}

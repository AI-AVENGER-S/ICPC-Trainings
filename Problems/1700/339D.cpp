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

#define all(x) x.begin(), x.end()бь

using namespace std;

using ll = long long;

const int MOD = 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int sz = 1 << n;

    vector<int> tree(2 * sz);

    for (int i = 0; i < sz; ++i) {
        cin >> tree[sz + i];
    }

    bool use_or = true;

    for (int len = sz / 2; len >= 1; len /= 2) {
        for (int i = len; i < 2 * len; ++i) {
            if (use_or) {
                tree[i] = tree[2 * i] | tree[2 * i + 1];
            } else {
                tree[i] = tree[2 * i] ^ tree[2 * i + 1];
            }
        }

        use_or = !use_or;
    }

    while (m--) {
        int p, b;
        cin >> p >> b;

        int v = sz + p - 1;
        tree[v] = b;

        use_or = true;

        while (v > 1) {
            v /= 2;

            if (use_or) {
                tree[v] = tree[2 * v] | tree[2 * v + 1];
            } else {
                tree[v] = tree[2 * v] ^ tree[2 * v + 1];
            }

            use_or = !use_or;
        }

        cout << tree[1] << '\n';
    }

    return 0;
}
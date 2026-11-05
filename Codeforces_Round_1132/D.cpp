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

bool check(int n, int k, int v, vector<vector<int>>& g) {
    vector<int> comp(n + 1, -1);
    int id = 0;

    for (int to : g[v]) {
        if (comp[to] != -1) continue;

        vector<int> st = {to};
        comp[to] = id;

        while (!st.empty()) {
            int u = st.back();
            st.pop_back();

            for (int w : g[u]) {
                if (w == v || comp[w] != -1) continue;

                comp[w] = id;
                st.push_back(w);
            }
        }

        id++;
    }

    for (int i = 1; i <= n; i++) {
        int j = k - i;

        if (j < 1 || j > n || i >= j) continue;

        if (comp[i] != comp[j]) {
            return true;
        }
    }

    return false;
}

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> g(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    if (n % 2 == 0) {
        cout << n + 1 << '\n';
        return;
    }

    vector<pair<int, int>> candidates = {
        {n, n},
        {n + 1, (n + 1) / 2},
        {n + 2, 1}
    };

    for (auto [k, v] : candidates) {
        if (check(n, k, v, g)) {
            cout << k << '\n';
            return;
        }
    }

    cout << n << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();
}
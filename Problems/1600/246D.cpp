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

vector<vector<pair<int, int>>> graph;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> c(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    graph.resize(n + 1);

    int start = -1;
    
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        if (start == -1) start = u;

        graph[u].emplace_back(v, c[v]);
        graph[v].emplace_back(u, c[u]);
    }

    unordered_map<int, set<int>> color_count;

    for (int u = 1; u <= n; ++u) {
        for (const auto &[v, color] : graph[u]) {
            if (color != c[u]) {
                color_count[c[u]].insert(color);
            }
        }
    }

    int ans = INT_MAX;
    int best = -1;

    for (int i = 1; i <= n; ++i) {
        if (!color_count[c[i]].empty()) {
            int cnt = color_count[c[i]].size();

            if (cnt > best || (cnt == best && c[i] < ans)) {
                best = cnt;
                ans = c[i];
            }
        }
    }

    cout << (ans == INT_MAX ? *min_element(c.begin() + 1, c.end()) : ans) << '\n';
        

    return 0;
}
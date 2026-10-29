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


int n;
vector<pair<int, int>> intervals;
vector<vector<int>> g;
vector<bool> used;

bool canGo(int a, int b, int c, int d) {
    return (c < a && a < d) ||
           (c < b && b < d);
}

void dfs(int v) {
    used[v] = true;

    for (int to = 0; to < n; ++to) {
        if (g[v][to] && !used[to]) {
            dfs(to);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;

    g.assign(q, vector<int>(q, 0));

    while (q--) {
        int type, x, y;
        cin >> type >> x >> y;

        if (type == 1) {
            int id = intervals.size();

            for (int i = 0; i < id; ++i) {
                auto [a, b] = intervals[i];

                if (canGo(a, b, x, y)) {
                    g[i][id] = 1;
                }

                if (canGo(x, y, a, b)) {
                    g[id][i] = 1;
                }
            }

            intervals.push_back({x, y});
            ++n;
        } else {
            used.assign(n, false);
            dfs(x - 1);

            cout << (used[y - 1] ? "YES" : "NO") << '\n';
        }
    }
}

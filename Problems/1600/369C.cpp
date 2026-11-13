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

vector<vector<int>> graph;
vector<int> dp;
vector<bool> white;
vector<int> ans_vec;

void calc(int v, int prev) {
    dp[v] = white[v];

    for (int u: graph[v]) {
        if (u == prev) continue;

        calc(u, v);
        dp[v] += dp[u];
    }

    if (white[v] && dp[v] == 1)
        ans_vec.push_back(v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    graph.resize(n + 1);
    dp.resize(n + 1);
    white.resize(n + 1, false);

    for (int i = 0; i < n - 1; ++i) {
        int x, y, t;
        cin >> x >> y >> t;

        graph[x].push_back(y);
        graph[y].push_back(x);

        if (t == 2) {
            white[x] = true;
            white[y] = true;
        }
    }

    calc(1, 0);

    cout << ans_vec.size() << '\n';

    for (int el: ans_vec)
        cout << el << ' ';

    cout << '\n';

    return 0;
}
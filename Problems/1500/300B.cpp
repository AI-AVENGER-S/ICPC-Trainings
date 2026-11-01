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


vector<vector<int>> g;
vector<bool> used;

void dfs(int v, vector<int>& comp) {
    used[v] = true;
    comp.push_back(v);

    for (int to : g[v]) {
        if (!used[to]) {
            dfs(to, comp);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    g.resize(n + 1);
    used.resize(n + 1, false);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<vector<int>> teams;
    vector<vector<int>> pairs;
    vector<int> singles;

    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            vector<int> comp;
            dfs(i, comp);

            if (comp.size() > 3) {
                cout << -1 << '\n';
                return 0;
            }

            if (comp.size() == 3) {
                teams.push_back(comp);
            } 
            else if (comp.size() == 2) {
                pairs.push_back(comp);
            } 
            else {
                singles.push_back(comp[0]);
            }
        }
    }

    if (pairs.size() > singles.size()) {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 0; i < pairs.size(); ++i) {
        teams.push_back({
            pairs[i][0],
            pairs[i][1],
            singles[i]
        });
    }

    for (int i = pairs.size(); i < singles.size(); i += 3) {
        teams.push_back({
            singles[i],
            singles[i + 1],
            singles[i + 2]
        });
    }

    for (auto team : teams) {
        cout << team[0] << ' '
             << team[1] << ' '
             << team[2] << '\n';
    }
}
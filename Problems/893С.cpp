#include <iostream>
#include <vector>
#include <cmath>

using ll = long long;
using namespace std;

int dfs(int u, int &min_cost, vector<bool> &visited, const vector<vector<int>> &graph, const vector<int> & costs) {
    visited[u] = true;
    min_cost = min(min_cost, costs[u]);

    for (int v: graph[u]){
        if (!visited[v]){
            dfs(v, min_cost, visited, graph, costs);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> costs(n + 1, 0);
    for (int i = 1; i < n + 1; ++i) cin >> costs[i];

    vector<vector<int>> graph(n + 1); 
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    ll result = 0;
    vector<bool> visited(n + 1, false);
    for (int i = 1; i < n + 1; ++i){
        if (!visited[i]){
            int min_cost = 2 * pow(10, 9);
            dfs(i, min_cost, visited, graph, costs);
            result += min_cost;
        }
    }

    cout << result << '\n';
    return 0;
}
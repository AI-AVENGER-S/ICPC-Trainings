#include <iostream>
#include <vector>

using namespace std;

int dfs(int u, const vector<int> &graph, vector<int> &visited) {
    visited[u] = 1;
    int v = graph[u];

    if (!visited[v]){
        return dfs(v, graph, visited);
    } else if (visited[v]){
        return v;
    }
}




int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> graph(n + 1, 0);

    for (int i = 1; i < n + 1; ++i){
        cin >> graph[i];
    }

    for (int i = 1; i < n + 1; ++i){
        vector<int> visited(n + 1, 0);
        cout << dfs(i, graph, visited) << ' ';
    }
    cout << '\n';

    return 0;
}
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

const int MOD = 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    if (n > m) {
        cout << n - m << '\n';
        return 0;
    }
    
    vector<vector<int>> graph(2 * m + 1, vector<int>(2));
    for (int i = 1; i <= 2 * m; ++i){
        if (i <= m) graph[i].push_back(2 * i);
        if (i > 1) graph[i].push_back(i - 1);
    }
    
    queue<pair<int, int>> q({{n, 0}});
    vector<bool> visited(2 * m + 1, false);
    
    while (!q.empty()){
        auto [u, path] = q.front();
        q.pop();
        if (u == m) {
            cout << path << '\n';
            return 0;
        }
        
        for (auto v: graph[u]){
            if (!visited[v]) {
                int new_path = path + 1;

                q.push({v, new_path});
                visited[v] = true;       
            }
                
        }
    }
    
    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>
#include <cassert>
#include <cstring>

using namespace std;

struct Point {
    int x, y;
};

int n;
vector<Point> points;
vector<bool> visited;

void dfs(int current) {
    visited[current] = true;
    
    for (int i = 0; i < n; ++i) {
        if (!visited[i] && (points[current].x == points[i].x || points[current].y == points[i].y)) {
            dfs(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;

    points.resize(n);
    visited.assign(n, false);
    
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }
    
    int components_count = 0;
    
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            ++components_count;
            dfs(i);
        }
    }
    
    cout << components_count - 1 << "\n";
    
    return 0;
}
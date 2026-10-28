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


int n, m;
vector<string> matrix;
vector<vector<bool>> visited;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool dfs(int x, int y, int px, int py) {
    visited[x][y] = true;

    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
            continue;
        }

        if (matrix[nx][ny] != matrix[x][y]) {
            continue;
        }

        if (!visited[nx][ny]) {
            if (dfs(nx, ny, x, y)) {
                return true;
            }
        } else if (nx != px || ny != py) {
            return true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    matrix.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> matrix[i];
    }

    visited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                if (dfs(i, j, -1, -1)) {
                    cout << "Yes"<< '\n';
                    return 0;
                }
            }
        }
    }

    cout << "No" << '\n';
    return 0;
}
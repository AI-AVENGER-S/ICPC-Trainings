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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<string> maze(n);
    int x = -1, y = -1;
    
    for (int i = 0; i < n; ++i) {
        cin >> maze[i];
        if (x == -1) {
            for (int j = 0; j < m; ++j) {
                if (maze[i][j] == '.') {
                    x = i;
                    y = j;
                }
            }
        }
    }

    vector<pair<int, int>> order;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    vector<pair<int, int>> st = {{x, y}};
    visited[x][y] = true;

    while (!st.empty()) {
        auto [x, y] = st.back();
        st.pop_back();

        order.push_back({x, y});

        for (auto [dx, dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;

            if (nx >= 0 && nx < n &&
                ny >= 0 && ny < m &&
                maze[nx][ny] == '.' &&
                !visited[nx][ny]) {

                visited[nx][ny] = true;
                st.push_back({nx, ny});
            }
        }
    }

    for (int i = 0; i < k; i++) {
        auto [x, y] = order[order.size() - i - 1];
        maze[x][y] = 'X';
    }
    
    for (auto &row : maze) {
        for (auto &cell : row) {
            cout << cell;
        }
        cout << "\n";
    }


    return 0;
}


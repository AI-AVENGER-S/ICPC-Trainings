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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> path;

    for (int i = 1; i <= n; i++) {
        if (i & 1) {
            for (int j = 1; j <= m; j++) {
                path.push_back({i, j});
            }
        } else {
            for (int j = m; j >= 1; j--) {
                path.push_back({i, j});
            }
        }
    }

    int pos = 0;

    for (int i = 0; i < k; i++) {
        int len;

        if (i == k - 1) {
            len = n * m - pos;
        } else {
            len = 2;
        }

        cout << len << ' ';

        for (int j = 0; j < len; j++) {
            cout << path[pos].first << ' '
                 << path[pos].second << ' ';
            pos++;
        }

        cout << '\n';
    }

    return 0;
}
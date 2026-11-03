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

    int n, m;
    cin >> n >> m;

    vector<string> s(n);

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    vector<bool> resolved(n - 1, false);

    int ans = 0;

    for (int j = 0; j < m; j++) {
        bool bad = false;

        for (int i = 0; i < n - 1; i++) {
            if (!resolved[i] && s[i][j] > s[i + 1][j]) {
                bad = true;
                break;
            }
        }

        if (bad) {
            ans++;
            continue;
        }

        for (int i = 0; i < n - 1; i++) {
            if (!resolved[i] && s[i][j] < s[i + 1][j]) {
                resolved[i] = true;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
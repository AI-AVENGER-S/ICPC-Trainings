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

const int MOD = 100000000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;

    vector<vector<int>> dpn1(n1 + 1, vector<int>(n2 + 1, 0));
    vector<vector<int>> dpn2(n1 + 1, vector<int>(n2 + 1, 0));

    for (int i = 1; i <= min(k1, n1); ++i){
        dpn1[i][0] = 1;
    }

    for (int j = 1; j <= min(k2, n2); ++j){
        dpn2[0][j] = 1;
    }

    for (int i = 1; i <= n1; ++i) {
        for (int j = 1; j <= n2; ++j) {

            for (int x = 1; x <= k1 && x <= i; ++x) {
                dpn1[i][j] += dpn2[i - x][j];
                dpn1[i][j] %= MOD;
            }

            for (int y = 1; y <= k2 && y <= j; ++y) {
                dpn2[i][j] += dpn1[i][j - y];
                dpn2[i][j] %= MOD;
            }
        }
    }

    cout << (dpn1[n1][n2] + dpn2[n1][n2]) % MOD << '\n';

    
    return 0;
}

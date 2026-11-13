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
    int r, g, b;
    cin >> r >> g >> b;

    int ans = 0;

    for (int mix = 0; mix <= 2; mix++) {
        if (r >= mix && g >= mix && b >= mix) {
            int cur = mix + (r - mix) / 3 + (g - mix) / 3 + (b - mix) / 3;

            ans = max(ans, cur);
        }
    }

    cout << ans << '\n';
}
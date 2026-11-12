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
    int n, sum = 0;
    cin >> n;

    int cnt[10] = {};

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ++cnt[x];
        sum += x;
    }

    if (!cnt[0]) {
        cout << -1 << '\n';
        return 0;
    }

    int r = sum % 3;

    if (r != 0) {
        bool found = false;

        for (int i = 1; i <= 9; i++) {
            if (i % 3 == r && cnt[i]) {
                --cnt[i];
                found = true;
                break;
            }
        }

        if (!found) {
            int need = 2;

            for (int i = 1; i <= 9 && need > 0; i++) {
                if (i % 3 == 3 - r) {
                    int take = min(cnt[i], need);
                    cnt[i] -= take;
                    need -= take;
                }
            }

            if (need > 0) {
                cout << -1 << '\n';
                return 0;
            }
        }
    }

    bool zero = true;

    for (int i = 1; i <= 9; i++)
        if (cnt[i]) zero = false;

    if (zero) {
        cout << 0 << '\n';
        return 0;
    }

    for (int i = 9; i >= 0; i--) {
        while (cnt[i]--) cout << i;     
    }
        
    return 0;
}
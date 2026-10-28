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

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    unordered_map<int, int> cnt;
    int l = 0;
    int distinct = 0;

    for (int r = 0; r < n; ++r) {
        if (cnt[a[r]] == 0) {
            ++distinct;
        }
        ++cnt[a[r]];

        while (distinct > k) {
            --cnt[a[l]];

            if (cnt[a[l]] == 0) {
                --distinct;
            }
            ++l;
        }

        while (distinct == k && cnt[a[l]] > 1) {
            --cnt[a[l]];
            ++l;
        }

        if (distinct == k) {
            cout << l + 1 << ' ' << r + 1 << '\n';
            return 0;
        }
    }

    cout << "-1 -1" << '\n';

    return 0;

}
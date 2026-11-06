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

    string receipt;
    cin >> receipt;

    int nb, ns, nc;
    cin >> nb >> ns >> nc;

    int pb, ps, pc;
    cin >> pb >> ps >> pc;

    ll r;
    cin >> r;

    ll left = 0, right = 1e13;

    while (left <= right) {
        ll mid = (left + right) / 2;

        ll need_b = max(0LL, mid * count(all(receipt), 'B') - nb);
        ll need_s = max(0LL, mid * count(all(receipt), 'S') - ns);
        ll need_c = max(0LL, mid * count(all(receipt), 'C') - nc);

        ll cost = need_b * pb + need_s * ps + need_c * pc;

        if (cost <= r) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << right << "\n";
    return 0;
}


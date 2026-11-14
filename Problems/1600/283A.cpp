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
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ll> a = {0};
    vector<ll> lazy = {0};

    ll sum = 0;

    while (n--) {
        int t;
        cin >> t;

        if (t == 1) {
            int k, x;
            cin >> k >> x;

            sum += 1LL * k * x;
            lazy[k - 1] += x;
        }
        else if (t == 2) {
            int k;
            cin >> k;

            a.push_back(k);
            lazy.push_back(0);

            sum += k;
        }
        else {
            sum -= a.back() + lazy.back();

            if (a.size() > 1){
                lazy[a.size() - 2] += lazy.back();
            }

            a.pop_back();
            lazy.pop_back();
        }

        cout << fixed << setprecision(10)
             << (double)sum / a.size() << '\n';
    }

    return 0;
}
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


bool check(int k, vector<int>& a, int n) {
    int step = n / k;

    for (int start = 0; start < step; ++start) {
        bool ok = true;

        for (int pos = start; pos < n; pos += step) {
            if (a[pos] == 0) {
                ok = false;
                break;
            }
        }

        if (ok) return true;
    }

    return false;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 1; i * i <= n; ++i) {
        if (n % i != 0) continue;

        int d1 = i;
        int d2 = n / i;

        if (d1 >= 3 && check(d1, a, n)) {
            cout << "YES" << '\n';
            return 0;
        }

        if (d2 >= 3 && d2 != d1 && check(d2, a, n)) {
            cout << "YES" << '\n';
            return 0;
        }
    }

    cout << "NO" << '\n';

    return 0;
}
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

vector<bool> is_prime(200000 + 1, true);

void sieve() {
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= 200000; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= 200000; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    for (int i = 0; i < n; ++i) {

        if (is_prime[a[i]]) {
            cout << a[i] << " ";
            continue;
        }

        int p = a[i] + 1;

        while (!is_prime[p]) ++p;

        cout << p << " ";
    }

    cout << "\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    sieve();

    while (t--) {
        solve();
    }

    return 0;
}
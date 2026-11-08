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

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        cout << "? 1 " << n << endl;

        int x;
        cin >> x;

        if (x == -1) return 0;

        if (x == 0 || x == n) {
            cout << "! NO" << endl;
            continue;
        }

        cout << "? 1 " << x << endl;

        int cnt;
        cin >> cnt;

        if (cnt == -1) return 0;

        if (cnt == x) {
            cout << "! NO" << endl;
        }
        else {
            cout << "! YES" << endl;
        }
    }

    return 0;
}
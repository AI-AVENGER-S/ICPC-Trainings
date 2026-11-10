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

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(all(a));

    int l = 0;
    int r = n / 2; 
    int paired = 0;

    while (l < n / 2 && r < n) {
        if (a[l] * 2 <= a[r]) {
            ++paired;
            ++l;
            ++r;
        } else {
            ++r;
        }
    }

    cout << n - paired << "\n";

    return 0;
}
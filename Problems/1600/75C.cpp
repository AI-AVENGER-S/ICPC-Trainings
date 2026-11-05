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

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    int g = gcd(a, b);

    vector<int> divisors;
    for (int i = 1; i * i <= g; i++) {
        if (g % i == 0) {
            divisors.push_back(i);
            if (i * i != g) {
                divisors.push_back(g / i);
            }
        }
    }

    sort(all(divisors));

    int n;
    cin >> n;
    while (n--) {
        int low, high;
        cin >> low >> high;

        auto it = upper_bound(all(divisors), high);

        if (it != divisors.begin()) {
            --it;
            if (*it >= low) {
                cout << *it << "\n";
            } else {
                cout << -1 << "\n";
            }
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}
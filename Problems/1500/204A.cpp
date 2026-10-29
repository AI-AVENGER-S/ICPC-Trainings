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

ll f(ll n) {
    if (n < 10) return n;
    
    ll ans = n / 10 + 9;
    
    string s = to_string(n);
    int first_digit = s[0] - '0';
    int last_digit = s[s.size() - 1] - '0';
    
    if (last_digit < first_digit) {
        --ans;
    }
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll l, r;
    cin >> l >> r;

    cout << f(r) - f(l - 1) << "\n";
    
    return 0;
}

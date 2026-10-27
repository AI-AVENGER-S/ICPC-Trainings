#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <numeric>
#include <iomanip>
#include <cassert>
#include <cstring>

#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long;

const int MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;

    ll A = 0, B = 0, C = 0, D = 1;

    for (int i = 1; i < n + 1; i++) {
        ll newA = (B + C + D) % MOD;
        ll newB = (A + C + D) % MOD;
        ll newC = (A + B + D) % MOD;
        ll newD = (A + B + C) % MOD;

        A = newA;
        B = newB;
        C = newC;
        D = newD;
    }

    cout << D << '\n';
}
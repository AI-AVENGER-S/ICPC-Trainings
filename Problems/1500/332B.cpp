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

    vector<long long> pref(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pref[i] = pref[i - 1] + x;
    }

    vector<long long> s(n - k + 2);

    for (int i = 1; i <= n - k + 1; i++) {
        s[i] = pref[i + k - 1] - pref[i - 1];
    }

    long long bestSum = -1;
    int bestPos = -1;

    long long ansSum = -1;
    int ansA = -1, ansB = -1;

    for (int a = n - 2 * k + 1; a >= 1; a--) {
        int b = a + k;

        if (s[b] >= bestSum) {
            bestSum = s[b];
            bestPos = b;
        }

        long long total = s[a] + bestSum;

        if (total >= ansSum) {
            ansSum = total;
            ansA = a;
            ansB = bestPos;
        }
    }

    cout << ansA << ' ' << ansB << '\n';

    
    return 0;
}
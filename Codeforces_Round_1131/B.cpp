#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>
#include <cassert>
#include <cstring>

using namespace std;

void solve() {
    int r, s, p;
    cin >> r >> s >> p;

    char c;

    if (s >= p) {
        c = 'R';
    }
    else if (p >= r) {
        c = 'S';
    }
    else {
        c = 'P';
    }

    cout << string(r + s + p, c) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

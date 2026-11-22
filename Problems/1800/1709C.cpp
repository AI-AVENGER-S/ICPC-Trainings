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

const int MOD = 1;

void solve() {
    string s;
    cin >> s;

    vector<int> positions;
    int cnt_open = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') cnt_open++;
        if (s[i] == '?') positions.push_back(i);
    }

    int marks_open = (int)s.size() / 2 - cnt_open;
    int marks_closed = (int)positions.size() - marks_open;

    if (marks_open == 0 || marks_closed == 0) {
        cout << "YES" << '\n';
        return;
    }

    for (int i = 0; i < (int)positions.size(); ++i) {
        if (i < marks_open) {
            s[positions[i]] = '(';
        } else {
            s[positions[i]] = ')';
        }
    }

    swap(s[positions[marks_open - 1]], s[positions[marks_open]]);

    int balance = 0;
    for (char el : s) {
        if (el == '(') balance++;
        else balance--;

        if (balance < 0) {
            cout << "YES" << '\n';
            return;
        }
    }

    cout << "NO" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
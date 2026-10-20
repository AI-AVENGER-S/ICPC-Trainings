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

vector<int> compute_z_function(const string& s) {
    int n = s.length();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    int len1 = s1.length();
    int len2 = s2.length();

    vector<int> z1 = compute_z_function(s1);
    vector<int> z2 = compute_z_function(s2);

    int max_possible_len = min(len1, len2);
    int ans = 0;

    for (int i = 1; i <= max_possible_len; ++i) {
        bool ok1 = (len1 % i == 0) && (i == len1 || z1[i] == len1 - i);
        bool ok2 = (len2 % i == 0) && (i == len2 || z2[i] == len2 - i);
        if (ok1 && ok2) {
            if (s1.compare(0, i, s2, 0, i) == 0) {
                ans++;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}

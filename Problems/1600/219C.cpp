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

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    if (k == 2) {
        int ans1 = 0;
        string ans_str1 = s;
        
        for (int i = 0; i < n; ++i) {
            if (!(i & 1)) ans_str1[i] = 'A';
            else ans_str1[i] = 'B';

            if (s[i] != ans_str1[i]) ans1++;
        }

        int ans2 = 0;
        string ans_str2 = s;

        for (int i = 0; i < n; ++i) {
            if (!(i & 1)) ans_str2[i] = 'B';
            else ans_str2[i] = 'A';

            if (s[i] != ans_str2[i]) ans2++;
        }

        cout << min(ans1, ans2) << '\n';
        cout << ((ans1 == min(ans1, ans2)) ? ans_str1 : ans_str2) << '\n';
    }
    else {
        int ans = 0;

        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i - 1]) {
                for (int j = 0; j < k; ++j) {
                    char c = 'A' + j;

                    if (c != s[i - 1] &&
                        (i + 1 == n || c != s[i + 1])) {

                        s[i] = c;
                        ans++;
                        break;
                    }
                }
            }
        }
        cout << ans << '\n';
        cout << s << '\n';
    }

    return 0;
}
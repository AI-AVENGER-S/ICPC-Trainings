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

    int a, b, c;
    cin >> a >> b >> c;

    vector<int> ans(0);
    
    int sx = 81;
    for (int i = 1; i <= sx; ++i) {
        ll x = b * pow(i, a) + c;
        if (0 < x && x < (ll)pow(10, 9)) {
            int sum = 0;
            string x_str = to_string(x);
            for (char c : x_str) {
                if (isdigit(c)) {
                    sum += c - '0';
                }
            }
            if (sum == i) ans.push_back(x);
        }
    }

    cout << ans.size() << '\n';
    for (auto el: ans) cout << el << ' ';
    cout << '\n';
    
    return 0;
}
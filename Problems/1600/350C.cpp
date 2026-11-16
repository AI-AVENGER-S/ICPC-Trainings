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
    
    vector<pair<int, int>> pairs(n);
    for (int i = 0; i < n; ++i){
        cin >> pairs[i].first >> pairs[i].second;
    }

    sort(all(pairs), [](auto a, auto b) {
        return (ll)abs(a.first) + abs(a.second) < (ll)abs(b.first) + abs(b.second);
    });

    vector<string> ans;
    ans.reserve(n * 6); 

    for (int i = 0; i < n; ++i) {
        int x = pairs[i].first;
        int y = pairs[i].second;

        if (x != 0) ans.push_back("1 " + to_string(abs(x)) + (x > 0 ? " R" : " L"));
        if (y != 0) ans.push_back("1 " + to_string(abs(y)) + (y > 0 ? " U" : " D"));

        ans.push_back("2");

        if (x != 0) ans.push_back("1 " + to_string(abs(x)) + (x > 0 ? " L" : " R"));
        if (y != 0) ans.push_back("1 " + to_string(abs(y)) + (y > 0 ? " D" : " U"));

        ans.push_back("3");
    }

    cout << ans.size() << '\n';
    for (const auto& el : ans) {
        cout << el << '\n';
    }

    return 0;
}
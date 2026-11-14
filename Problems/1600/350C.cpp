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

    sort(all(pairs), [](auto x, auto y){
        return abs(x.first) + abs(x.second) < abs(y.first) + abs(y.second);
    });
    
    for (int i = 0; i < n; ++i){
        
    }

    return 0;
}
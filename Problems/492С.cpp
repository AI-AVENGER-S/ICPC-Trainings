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

#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, r, avg;
    cin >> n >> r >> avg;
    
    vector<pair<ll, ll>> exams(n);
    ll current_sum = 0;
    
    for(int i = 0; i < n; ++i){
        cin >> exams[i].first >> exams[i].second;
        current_sum += exams[i].first;
    }

    ll target_sum = avg * n;

    if (current_sum >= target_sum) {
        cout << 0 << '\n';
        return 0;
    }
    
    sort(all(exams), [](const auto& a, const auto& b) {
        if (a.second != b.second) return a.second < b.second;
        return a.first < b.first;
    });

    ll required_essays = 0;
    ll needed = target_sum - current_sum;

    for(int i = 0; i < n && needed > 0; ++i){
        ll max_to_add = r - exams[i].first; 
        
        ll points_to_take = min(needed, max_to_add);
        
        required_essays += points_to_take * exams[i].second;
        needed -= points_to_take;
    }

    cout << required_essays << '\n';

    return 0;
}

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

pair<string, string> split_file(const string& filename) {
    size_t tochka_position = filename.find('.');
    return {filename.substr(0, tochka_position), filename.substr(tochka_position + 1)};
}

void solve() {
    int n;
    cin >> n;
    
    vector<pair<string, string>> files(n);
    int id = -1;
    
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        files[i] = split_file(s);
        if (files[i].second == "EXE") {
            id = i;
        }
    }
    
    if (id == 0) {
        cout << files[0].first << "." << files[0].second << "\n";
        return;
    }
    
    for (int k = 1; k <= 8; ++k) {
        string new_base = string(k, 'A') + files[id].first;
        if (new_base.length() > 8) {
            new_base = new_base.substr(0, 8);
        }
        
        pair<string, string> candidate = {new_base, "EXE"};
        
        if (candidate < files[0]) {
            cout << candidate.first << "." << candidate.second << "\n";
            return;
        }
    }
    
    cout << "IMPOSSIBLE" << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int _;
    cin >> _;
    while (_--) {
        solve();
    }
    
    return 0;
}

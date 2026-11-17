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


vector<int> compute_sp(const string& s) {
    int n = s.length();
    vector<int> sp(n, 0);
    
    for (int i = 1; i < n; ++i) {
        int j = sp[i - 1];
        

        while (j > 0 && s[i] != s[j]) {
            j = sp[j - 1];
        }
        
        if (s[i] == s[j]) {
            ++j;
        }
        
        sp[i] = j;
    }
    
    return sp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    vector<int> sp = compute_sp(s);

    unordered_map<int, bool> ans(false);

    int k;
    k = sp[s.size() - 1];
    while (k > 0) {
        ans[k] = true;
        k = sp[k - 1];
    }

    int maxi = 0;
    for (int i = 1; i < s.size() - 1; ++i){
        if (ans[sp[i]]) maxi = max(maxi, sp[i]);
    }

    cout << (maxi ? s.substr(0, maxi) : "Just a legend") << '\n';
    return 0;
}

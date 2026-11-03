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


int solve(const vector<int>& dp, int l, int r) {
    return dp[r] - dp[l];
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int n = s.size();
    vector<int> dp(n + 1, 0);
    
    for(int i = 2; i < n + 1; ++i){
        if (s[i - 1] == s[i - 1 - 1]) dp[i] = dp[i - 1] + 1;
        else dp[i] = dp[i - 1];
    }

    int t;
    cin >> t;
    while(t--){
        int l, r;
        cin >> l >> r;
        cout << solve(dp, l, r) << "\n";
    }
    return 0;
}
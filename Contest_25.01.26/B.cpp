#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> pos_of(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> p[i];
        pos_of[p[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        int target = n - i;
        
        
        if (p[i] != target) {
            int L = i;
            int R = pos_of[target];
            
            reverse(p.begin() + L, p.begin() + R + 1);
            
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << p[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
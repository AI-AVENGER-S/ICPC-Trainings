#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        int bad = n * n - k;

        if (bad == 1) {
            cout << "NO" << '\n';
            continue;
        }

        cout << "YES" << '\n';

        vector<string> g(n, string(n, 'U'));

        if (bad == 0) {
            for (auto &row : g) cout << row << "\n";
            continue;
        }
        
        g[n - 1][n - 1] = 'L';
        --bad;

        for (int j = n - 2; j >= 0 && bad > 0; --j){
            g[n - 1][j] = 'R';
            --bad;
        }

        for (int i = n - 2; i >= 0 && bad > 0; --i){
            for (int j = n - 1; j >= 0 && bad > 0; --j){
                g[i][j] = 'D';
                --bad;
            }
        }
                
        for (auto &row : g)
            cout << row << "\n";
    }
}
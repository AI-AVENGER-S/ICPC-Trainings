#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;

    while (t--){
        int n;
        ll s, x;
        cin >> n >> s >> x;

        ll summ = 0;

        vector<int> a(n);

        for (int i = 0; i < n; ++i){
            cin >> a[i];
            summ += a[i];
        }

        if (s >= summ && (s - summ) % x == 0){
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    

    return 0;
}
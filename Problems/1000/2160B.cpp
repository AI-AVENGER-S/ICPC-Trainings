#include <iostream>
#include <vector>

#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> b(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }

        vector<int> a(n + 1, 0);
        ll prev = 0;
        int next_nessesary_num = 1;

        for (int i = 1; i <= n; i++) {
            ll di = b[i] - prev;
            prev = b[i];
            ll x = i - di;

            if (x == 0) {
                a[i] = next_nessesary_num;
                next_nessesary_num++;
            } else {
                a[i] = a[x];
            }
        }

        for (int i = 1; i <= n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <numeric>


#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        ll ans = -1;
        for (int p : primes) {
            bool found = false;
            for (int i = 0; i < n; i++) {
                if (gcd(a[i], p) == 1) {
                    found = true;
                    break;
                }
            }
            if (found) {
                ans = p;
                break;
            }
        }

        cout << ans << "\n";
    }
    
    return 0;
}
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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, d;
    cin >> n >> m >> d;
    
    vector<int> a(n * m, 0);
    
    for (int i = 0; i < n * m; ++i) {
        cin >> a[i];
    }
    
    int remainder = a[0] % d;
    for (int i = 1; i < n * m; ++i) {
        if (a[i] % d != remainder) {
            cout << -1 << "\n";
            return 0;
        }
    }
    
    sort(all(a));
    
    int median = a[n * m / 2];
    
    int steps = 0;
    for (int i = 0; i < n * m; ++i) {
        steps += abs(a[i] - median) / d;
    }
    
    cout << steps << "\n";
    

    return 0;
}

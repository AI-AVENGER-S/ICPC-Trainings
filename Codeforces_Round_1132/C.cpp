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

void solve()
{
    int n;
    cin >> n;

    int k = 0;
    for(int i = 1; i <= n; i++) k |= i;

    int m = 0;
    vector<int> ans(n, 0);

    for(int i = 1; i <= n; i++) m ^= i;

    int d = 0;
    while((k >> d) & 1) d++;

    for (int i = d; i >= 1; i--) {
        if (((m >> i) & 1) == 0) {
            int x = (1 << (i - 1));

            ans[x - 1] = 1;

            m ^= x;
            m ^= (x << 1);
        }
    }
        
    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";

    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
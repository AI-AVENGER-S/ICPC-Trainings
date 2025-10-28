#include <iostream>

#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        bool res = (a == b) && (b == c) && (c == d);
        string ans = res ? "YES" : "NO";
        cout << ans << '\n';
    }

    
    return 0;
}
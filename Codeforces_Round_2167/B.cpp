#include <iostream>
#include <vector>
#include <algorithm>

#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        
        vector<char> s(n, 0);
        for (int j = 0; j < n; ++j){
            cin >> s[j];
        }
        
        vector<char> t(n, 0);
        for (int j = 0; j < n; ++j){
            cin >> t[j];
        }

        sort(all(s));
        sort(all(t));

        bool equal = true;
        for (int j = 0; j < n; ++j) {
            if (s[j] != t[j]) {
                equal = false;
                break;
            }
        }

        cout << (equal ? "YES" : "NO") << '\n';

    }

    return 0;
}
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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s1;
    cin >> s1;

    int k;
    cin >> k;

    if (s1.size() % k != 0) {
        cout << "NO" << '\n';
        return 0;
    }
    int border = s1.size() / k;

    for(int i = 0; i < k; ++i) {
        int l = border * i;
        int r = border * (i + 1) - 1;
        
        while (l < r) {
            if (s1[l] != s1[r]) {
                cout << "NO" << '\n';
                return 0;
            }
            ++l;
            --r;
        }
    }

    cout << "YES" << '\n';
    return 0;
}
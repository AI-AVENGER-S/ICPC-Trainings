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
    
    string s1, s2;
    cin >> s1 >> s2;

    if (s1.size() != s2.size()) {
        cout << "NO" << '\n';
        return 0;
    }

    int counter = 0;
    char top, bottom;

    for (int i = 0; i < s1.size(); ++i) {
        if (s1[i] != s2[i]){
            ++counter;
            if (counter == 1) {
                top = s1[i];
                bottom = s2[i];
            }
            else if (counter == 2) {
                if (bottom != s1[i] || top != s2[i]) {
                    cout << "NO" << '\n';
                    return 0;
                }
            }
            else {
                cout << "NO" << '\n';
                return 0;
            }
        }
    }

    if (counter == 2) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }

    return 0;
}
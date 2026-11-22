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

const int MOD = 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    string st;

    for (char c : s) {
        if (!st.empty() && st.back() == c) {
            st.pop_back();
        }
        else {
            st.push_back(c);
        }
    }

    cout << (st.empty() ? "Yes" : "No") << '\n';

    return 0;
}
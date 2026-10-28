#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <numeric>
#include <iomanip>
#include <cassert>
#include <cstring>

#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string a;
    string b;

    cin >> a >> b;

    if (a.size() != b.size()) {
        cout << "NO" << '\n';
        return 0;
    }
    if (a == b) {
        cout << "YES" << '\n';
        return 0;
    }

    vector<int> aCount(2, 0);
    vector<int> bCount(2, 0);

    for (char c : a) aCount[c - '0']++;

    for (char c : b) bCount[c - '0']++;
    
    if (aCount[0] == a.size() || bCount[0] == b.size()) {
        cout << "NO" << '\n';
        return 0;
    }

    cout << "YES" << '\n';
    return 0;
}
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

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int p, q;
    
    if (a * d <= b * c) {
        p = b * c - a * d;
        q = b * c;
    } else {
        p = a * d - b * c;
        q = a * d;
    }
    
    int g = gcd(p, q);
    cout << p / g << "/" << q / g << "\n";

    return 0;
}

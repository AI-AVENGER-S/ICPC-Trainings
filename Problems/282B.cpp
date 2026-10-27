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

const int MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int diff = 0;
    string answer;

    for (int i = 0; i < n; i++) {
        int a, g;
        cin >> a >> g;

        if (diff + a <= 500) {
            answer += 'A';
            diff += a;
        } else {
            answer += 'G';
            diff -= g;
        }
    }

    cout << answer << '\n';

}
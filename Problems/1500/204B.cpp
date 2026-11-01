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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    unordered_map<int, int> top_cnt;
    unordered_map<int, int> bot_cnt;

    unordered_map<int, int> all_cnt;

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i){
        int top, bot;
        cin >> top >> bot;

        ++top_cnt[top];
        ++bot_cnt[bot];

        ++all_cnt[top];
        if (top != bot) ++all_cnt[bot];
    }

    int target = (n + 1) / 2;
    int min_ans = 2e9;

    for (auto [color, cnt] : all_cnt) {
        if (cnt >= target) {
            if (top_cnt[color] >= target) {
                min_ans = min(min_ans, 0);
            } else {
                min_ans = min(min_ans, target - top_cnt[color]);
            }
        }
    }

    if (min_ans == 2e9) {
        cout << "-1" << '\n';
    } else {
        cout << min_ans << '\n';
    }

    return 0;
}
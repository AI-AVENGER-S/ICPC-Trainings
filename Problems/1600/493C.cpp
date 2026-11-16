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

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    int m;
    cin >> m;

    vector<int> b(m);
    for (int &x : b) cin >> x;

    vector<pair<int, int>> events;

    for (int x : a) events.push_back({x, 0});
    for (int x : b) events.push_back({x, 1});

    sort(all(events));

    int scoreA = 3 * n;
    int scoreB = 3 * m;

    int bestA = scoreA;
    int bestB = scoreB;

    for (int i = 0; i < events.size();) {
        int j = i;
        int cntA = 0, cntB = 0;

        while (j < events.size() &&
               events[j].first == events[i].first) {

            if (events[j].second == 0) cntA++;
            else cntB++;

            j++;
        }

        scoreA -= cntA;
        scoreB -= cntB;

        if (scoreA - scoreB > bestA - bestB ||
            (scoreA - scoreB == bestA - bestB &&
             scoreA > bestA)) {

            bestA = scoreA;
            bestB = scoreB;
        }

        i = j;
    }

    cout << bestA << ":" << bestB << '\n';

    return 0;
}
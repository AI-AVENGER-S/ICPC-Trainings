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


struct Request {
    int c, p, id;
};

struct Table {
    int r, id;
    bool used = false;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<Request> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].c >> a[i].p;
        a[i].id = i + 1;
    }

    int k;
    cin >> k;

    vector<Table> t(k);

    for (int i = 0; i < k; i++) {
        cin >> t[i].r;
        t[i].id = i + 1;
    }

    sort(all(a), [](auto x, auto y) {
        return x.p > y.p;
    });

    sort(all(t), [](auto x, auto y) {
        return x.r < y.r;
    });

    int sum = 0;
    vector<pair<int, int>> ans;

    for (auto req : a) {
        for (auto &table : t) {
            if (!table.used && table.r >= req.c) {
                table.used = true;
                sum += req.p;

                ans.push_back({req.id, table.id});
                break;
            }
        }
    }

    cout << ans.size() << ' ' << sum << '\n';

    for (auto [request, table] : ans)
        cout << request << ' ' << table << '\n';
    
    return 0;
}
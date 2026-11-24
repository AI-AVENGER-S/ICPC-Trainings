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


struct SegTree {
    int n;
    vector<ll> tree, lazy;

    SegTree(const vector<ll>& a) {
        n = (int)a.size();
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        build(1, 0, n - 1, a);
    }

    void build(int v, int tl, int tr, const vector<ll>& a) {
        if (tl == tr) {
            tree[v] = a[tl];
            return;
        }

        int tm = (tl + tr) / 2;

        build(v * 2, tl, tm, a);
        build(v * 2 + 1, tm + 1, tr, a);

        tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
    }

    void apply(int v, ll val) {
        tree[v] += val;
        lazy[v] += val;
    }

    void push(int v) {
        if (lazy[v] == 0) return;

        apply(v * 2, lazy[v]);
        apply(v * 2 + 1, lazy[v]);

        lazy[v] = 0;
    }

    void update(int v, int tl, int tr,
                int l, int r, ll val) {
        if (l > r) return;

        if (l <= tl && tr <= r) {
            apply(v, val);
            return;
        }

        push(v);

        int tm = (tl + tr) / 2;

        update(v * 2, tl, tm, l, min(r, tm), val);
        update(v * 2 + 1, tm + 1, tr,
               max(l, tm + 1), r, val);

        tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
    }

    ll query(int v, int tl, int tr, int l, int r) {
        if (l > r) return LLONG_MAX;

        if (l <= tl && tr <= r) {
            return tree[v];
        }

        push(v);

        int tm = (tl + tr) / 2;

        ll left = query(v * 2, tl, tm, l, min(r, tm));
        ll right = query(v * 2 + 1, tm + 1, tr,
                         max(l, tm + 1), r);

        return min(left, right);
    }

    void update(int l, int r, ll val) {
        update(1, 0, n - 1, l, r, val);
    }

    ll query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ll> a(n);

    for (auto& el : a) {
        cin >> el;
    }

    vector<ll> sums(n);
    vector<pair<ll, int>> pairs;

    ll cur = 0;
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] >= 0) {
            cur += a[i];
            ++ans;
        } 
        else {
            pairs.push_back({a[i], i});
        }

        sums[i] = cur;
    }

    sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) {
        if (a.first != b.first) {
            return a.first > b.first;
        }
        return a.second > b.second;
    });

    SegTree st(sums);

    for (auto [val, pos] : pairs) {
        if (st.query(pos, n - 1) + val >= 0) {
            ++ans;
            st.update(pos, n - 1, val);
        }
    }

    cout << ans << '\n';

    return 0;
}
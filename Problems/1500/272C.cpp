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
using namespace std;

using ll = long long;

struct SegTree {
    int n;
    vector<ll> mx, lazy;
    vector<bool> has_lazy;

    
    SegTree(vector<ll>& a) {
        n = a.size();
        mx.resize(4 * n);
        lazy.resize(4 * n);
        has_lazy.resize(4 * n, false);

        build(1, 0, n - 1, a);
    }

    void build(int v, int l, int r, vector<ll>& a) {
        if (l == r) {
            mx[v] = a[l];
            return;
        }

        int mid = (l + r) / 2;

        build(v * 2, l, mid, a);
        build(v * 2 + 1, mid + 1, r, a);

        mx[v] = max(mx[v * 2], mx[v * 2 + 1]);
    }

    void apply(int v, ll val) {
        mx[v] = val;
        lazy[v] = val;
        has_lazy[v] = true;
    }

    void push(int v) {
        if (!has_lazy[v]) return;

        apply(v * 2, lazy[v]);
        apply(v * 2 + 1, lazy[v]);

        has_lazy[v] = false;
    }

    void update(int v, int l, int r, int ql, int qr, ll val) {
        if (ql > r || qr < l) return;

        if (ql <= l && r <= qr) {
            apply(v, val);
            return;
        }

        push(v);

        int mid = (l + r) / 2;

        update(v * 2, l, mid, ql, qr, val);
        update(v * 2 + 1, mid + 1, r, ql, qr, val);

        mx[v] = max(mx[v * 2], mx[v * 2 + 1]);
    }

    ll query(int v, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return mx[v];
        }

        push(v);

        int mid = (l + r) / 2;

        if (qr <= mid)
            return query(v * 2, l, mid, ql, qr);

        if (ql > mid)
            return query(v * 2 + 1, mid + 1, r, ql, qr);

        return max(
            query(v * 2, l, mid, ql, qr),
            query(v * 2 + 1, mid + 1, r, ql, qr)
        );
    }

    ll get_max(int r) {
        return query(1, 0, n - 1, 0, r);
    }

    void set_prefix(int r, ll val) {
        update(1, 0, n - 1, 0, r, val);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ll> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    SegTree st(a);

    int m;
    cin >> m;

    while (m--) {
        int w;
        ll h;
        cin >> w >> h;

        ll height = st.get_max(w - 1);

        cout << height << '\n';

        st.set_prefix(w - 1, height + h);
    }

    return 0;
}
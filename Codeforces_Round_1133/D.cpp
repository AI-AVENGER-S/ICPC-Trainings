
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;

    vector<bool> present(3 * n + 1, false);

    int mx = 0;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        present[x] = true;
        mx = max(mx, x);
    }

    ll dp[8][3] = {};
    dp[0][0] = 1;

    for (int x = mx; x >= 1; --x) {
        ll ndp[8][3] = {};

        for (int mask = 0; mask < 8; ++mask) {
            for (int bad = 0; bad <= 2; ++bad) {

                if (dp[mask][bad] == 0) {
                    continue;
                }

                // take = 0: не выбираем x
                // take = 1: выбираем x
                int limit = present[x] ? 1 : 0;

                for (int take = 0; take <= limit; ++take) {

                    int new_bad = bad;

                    if (take == 1) {
                        int cnt = __builtin_popcount(mask);

                        if (cnt != 2) {
                            new_bad++;
                        }
                    }

                    if (new_bad > 2) {
                        continue;
                    }

                    int new_mask = ((mask << 1) & 7) | take;

                    ndp[new_mask][new_bad] += dp[mask][bad];
                    ndp[new_mask][new_bad] %= MOD;
                }
            }
        }

        for (int mask = 0; mask < 8; ++mask) {
            for (int bad = 0; bad <= 2; ++bad) {
                dp[mask][bad] = ndp[mask][bad];
            }
        }
    }

    // Суммируем все сбалансированные подмножества
    // Вычитаем пустое подмножество

    ll ans = 0;

    for (int mask = 0; mask < 8; ++mask) {
        for (int bad = 0; bad <= 2; ++bad) {
            ans = (ans + dp[mask][bad]) % MOD;
        }
    }

    ans = (ans - 1 + MOD) % MOD;

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

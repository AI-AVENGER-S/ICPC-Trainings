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

    vector<string> words(n);

    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    vector<vector<int>> g(26);
    vector<vector<bool>> used(26, vector<bool>(26, false));
    vector<int> indegree(26, 0);

    bool bad = false;

    for (int i = 0; i < n - 1; ++i) {
        string& word1 = words[i];
        string& word2 = words[i + 1];

        int len = min(word1.size(), word2.size());
        int j = 0;

        while (j < len && word1[j] == word2[j]) {
            ++j;
        }

        if (j == len) {
            if (word1.size() > word2.size()) {
                bad = true;
            }
        }
        else {
            int u = word1[j] - 'a';
            int v = word2[j] - 'a';

            if (!used[u][v]) {
                g[u].push_back(v);
                used[u][v] = true;
                indegree[v]++;
            }
        }
    }

    if (bad) {
        cout << "Impossible" << '\n';
        return 0;
    }

    queue<int> q;

    for (int i = 0; i < 26; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    string ans;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        ans += char('a' + u);

        for (int v : g[u]) {
            --indegree[v];

            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    if (ans.size() != 26) {
        cout << "Impossible" << '\n';
    }
    else {
        cout << ans << '\n';
    }

    return 0;
}
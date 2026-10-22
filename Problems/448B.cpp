#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>
#include <cassert>
#include <cstring>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s, t;
    cin >> s >> t;

    size_t s_idx = 0, t_idx = 0;
    while (s_idx < s.length() && t_idx < t.length()) {
        if (s[s_idx] == t[t_idx]) {
            t_idx++;
        }
        s_idx++;
    }

    if (t_idx == t.length()) {
        cout << "automaton" << '\n';
        return 0;
    }

    vector<int> count_s(26, 0);
    vector<int> count_t(26, 0);
    
    for (char c : s) count_s[c - 'a']++;
    for (char c : t) count_t[c - 'a']++;

    bool has_enough_letters = true;
    for (int i = 0; i < 26; ++i) {
        if (count_s[i] < count_t[i]) {
            has_enough_letters = false;
            break;
        }
    }

    if (!has_enough_letters) {
        cout << "need tree" << '\n';
    } else {
        if (s.length() == t.length()) {
            cout << "array" << '\n';
        } else {
            cout << "both" << '\n';
        }
    }
    return 0;
}

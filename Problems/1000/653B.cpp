#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>

#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    map<char, vector<string> > rev_ops;
    for (int i = 0; i < q; i++) {
        string a, b;
        cin >> a >> b;
        rev_ops[b[0]].push_back(a);
    }
    
    unordered_set<string> current;
    current.insert("a");
    
    for (int length = 1; length < n; ++length) {
        unordered_set<string> next_level;
        for (const string& s : current) {
            char first_char = s[0];
            if (rev_ops.count(first_char)) {
                for (const string& prefix : rev_ops[first_char]) {
                    string new_s = prefix + s.substr(1);
                    next_level.insert(new_s);
                }
            }
        }
        current = std::move(next_level);
    }
    
    cout << current.size() << endl;
    return 0;
}
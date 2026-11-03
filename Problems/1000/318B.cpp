#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int n = s.size();
    vector<int> heavy, metal;
    for (int i = 0; i <= n - 5; i++) {
        string sub = s.substr(i, 5);
        if (sub == "heavy") heavy.push_back(i);
        if (sub == "metal") metal.push_back(i);
    }

    ll counter = 0;
    int p = metal.size();
    int ptr = p;
    for (int i = heavy.size() - 1; i >= 0; --i){
        while (ptr > 0 && heavy[i] <= metal[ptr - 1]) {
            --ptr;
        }
        counter += (p - ptr);
    }

    cout << counter << '\n';

    return 0;
}
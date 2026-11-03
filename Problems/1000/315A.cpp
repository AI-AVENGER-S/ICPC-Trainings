#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
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
    
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    
    vector<int> open_count(1001, 0); 
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        open_count[b[i]]++;
    }
    
    int closed_bottles = 0;
    
    for (int i = 0; i < n; ++i) {
        int available_openers = open_count[a[i]];
        
        if (a[i] == b[i]) {
            available_openers--;
        }
        
        if (available_openers == 0) {
            closed_bottles++;
        }
    }
    
    cout << closed_bottles << '\n';
    
    return 0;
}

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

    int n;
    cin >> n;

    const int LIMIT = 1500000; 
    vector<bool> is_prime(LIMIT + 1, true);
    
    int count = 0;

    for (int p = 2; p <= LIMIT; ++p) {
        if (is_prime[p]) {
            cout << p << ' ';
            ++count;
            
            if (count == n) {
                break;
            }

            if ((long long)p * p <= LIMIT) {
                for (int i = p * p; i <= LIMIT; i += p) {
                    is_prime[i] = false;
                }
            }
        }
    }

    cout << "\n";
    return 0;
}

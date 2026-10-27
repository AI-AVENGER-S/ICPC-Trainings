#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    array<vector<int>, 10> positions;

    for (int i = 0; i < (int)s.size(); i++) {
        int digit = s[i] - '0';
        positions[digit].push_back(i);
    }

    for (int candidate = 0; candidate < 1000; candidate += 8) {
        string number = to_string(candidate);

        int lastPosition = -1;
        bool found = true;

        for (char character : number) {
            int digit = character - '0';

            const vector<int>& digitPositions = positions[digit];

            auto it = upper_bound(
                digitPositions.begin(),
                digitPositions.end(),
                lastPosition
            );

            if (it == digitPositions.end()) {
                found = false;
                break;
            }

            lastPosition = *it;
        }

        if (found) {
            cout << "YES" << '\n';
            cout << number << '\n';
            return 0;
        }
    }

    cout << "NO" << '\n';

    return 0;
}
#include <iostream>
#include <vector>


using namespace std;

long long solve(int cubes, int height){
    long long sum = 1LL * height * (height + 1) * (height + 2) / 6;
    return sum - cubes;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int l = 1, r = pow(10, 2);

    while (l <= r){
        int mid = (l + r) / 2;
        if (solve(n, mid) == 0){
            cout << mid << "\n";
            return 0;
        }
        else if (solve(n, mid) > 0) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    cout << r << "\n";
    return 0;

}
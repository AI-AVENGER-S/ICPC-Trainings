#include <iostream>
#include <vector>
#include <algorithm> 

#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    
    int N;
    int K;
    cin >> N >> K;
    
    vector<ll> series(N, 0);
    for(int i = 0; i < N; ++i){
        cin >> series[i];
    }

    vector<ll> diff(N - 1, 0);
    for(int i = 0; i < N - 1; ++i){
        diff[i] = series[i + 1] - series[i] - 1;
    }

    ll result = N + K;
    for (int i = 0; i < N - 1; ++i){
        result += min(static_cast<ll>(K), diff[i]);
    }

    cout << result << '\n';


    return 0;
}

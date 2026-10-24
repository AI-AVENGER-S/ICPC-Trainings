#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Ускоряем ввод-вывод
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> color(n + 1, 0);
    
    for (int i = 0; i < m; ++i) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        
        if (color[t1] != 0) {
            if (color[t1] == 1) { color[t2] = 2; color[t3] = 3; }
            else if (color[t1] == 2) { color[t2] = 1; color[t3] = 3; }
            else if (color[t1] == 3) { color[t2] = 1; color[t3] = 2; }
        } 
        else if (color[t2] != 0) {
            if (color[t2] == 1) { color[t1] = 2; color[t3] = 3; }
            else if (color[t2] == 2) { color[t1] = 1; color[t3] = 3; }
            else if (color[t2] == 3) { color[t1] = 1; color[t3] = 2; }
        } 
        else if (color[t3] != 0) {
            if (color[t3] == 1) { color[t1] = 2; color[t2] = 3; }
            else if (color[t3] == 2) { color[t1] = 1; color[t2] = 3; }
            else if (color[t3] == 3) { color[t1] = 1; color[t2] = 2; }
        } 
        else {
            color[t1] = 1;
            color[t2] = 2;
            color[t3] = 3;
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        cout << color[i] << (i == n ? "\n" : " ");
    }
    
    return 0;
}

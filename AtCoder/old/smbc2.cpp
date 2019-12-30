#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int res = 0;
    for(double i = 1; i < n; ++i){

        if(i * 1.08 == n) {
            cout << i << endl;
            return 0;
        }
    }
    cout << ":(" << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    for(int i = 2; i*i <= n; ++i){
        if(n%i == 0 && n/i >= 2){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
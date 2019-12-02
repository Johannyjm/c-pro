#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    for(int v = 1; v <= n; ++v){
        int price = v * 1.08;
        if(price == n){
            cout << v << endl;
            return 0;
        }
    }
    cout << ":(" << endl;
}
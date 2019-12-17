#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int a[n];
    int best = -1;
    int better = -1;

    for (int i = 0; i < n; ++i){
        cin >> a[i];
        if(a[i] > best) {
            better = best;
            best = a[i];
        }
        else if(a[i] > better) better = a[i];
    }

    for (int i = 0; i < n; ++i){
        if(a[i] == best) cout << better << endl;
        else cout << best << endl;
    }
}
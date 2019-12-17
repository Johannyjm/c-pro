#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    int corrected = 0;
    for(int i = 1; i <= n; ++i){
        int p;
        cin >> p;
        if(i != p) corrected++;
    }

    if(corrected == 0 || corrected == 2) cout << "YES" << endl;
    else cout << "NO" << endl;
}
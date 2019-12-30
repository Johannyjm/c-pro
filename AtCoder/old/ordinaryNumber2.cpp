#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    int res = 0;
    int p1, p2, p3;
    cin >> p1 >> p2;

    for(int i = 0; i < n-2; ++i){
        cin >> p3;
        if ((p1-p2) * (p3-p2) < 0) res++;
        p1 = p2;
        p2 = p3;
    }

    
    cout << res << endl;
}
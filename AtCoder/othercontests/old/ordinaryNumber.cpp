#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    int p1, p2, p3;
    cin >> p1 >> p2 >> p3;
    int res = 0;
    if((p1 < p2 && p2 < p3) || (p1 > p2 && p2 > p3)) res++;
    
    for (int i = 3; i < n; ++i){
        p1 = p2;
        p2 = p3;
        cin >> p3;
        if((p1 < p2 && p2 < p3) || (p1 > p2 && p2 > p3)) res++;
    }
    cout << res << endl;
}
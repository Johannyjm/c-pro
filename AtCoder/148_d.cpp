#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    int res = 0;
    int ptr = 1;
    for (int i = 0; i < n; ++i){
        int a;
        cin >> a;
        // cout << ptr << " " << a << endl;
        // cout << res << endl;
        if(a != ptr) res++;
        else ptr++;
    }
    if(res==n)cout << -1 << endl;
    else cout << res << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, x;
    cin >> n >> x;
    int current = 0;
    int res = 1;

    for (int i = 0; i < n; ++i){
        int l;
        cin >> l;
        current += l;

        if(current <= x) res++;
    }
    cout << res << endl;
}
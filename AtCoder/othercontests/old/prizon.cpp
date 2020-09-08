#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int L = 0;
    int R = 100001;

    for(int i = 0; i < m; ++i){
        int l, r;
        cin >> l >> r;
        if(L<l) L = l;
        if(R>r) R = r;
    }

    cout << max(0, R - L + 1) << endl;
}
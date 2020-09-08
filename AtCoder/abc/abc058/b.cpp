#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string o, e;
    cin >> o >> e;

    rep(i, e.length()){
        cout << o[i];
        cout << e[i];
    }
    if(o.length()>e.length()) cout << o[o.length()-1];

    cout << endl;
}
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string n;
    cin >> n;

    string res = "";
    rep(i, 4-n.size()) res += '0';
    res += n;

    cout << res << endl;

    return 0;
}
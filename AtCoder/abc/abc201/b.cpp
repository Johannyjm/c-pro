#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pair<int, string>> ts(n);
    rep(i, n){
        string s;
        int t;
        cin >> s >> t;
        ts[i] = {t, s};
    }

    sort(ts.begin(), ts.end(), greater<pair<int, string>>());

    cout << ts[1].second << endl;

    return 0;
}
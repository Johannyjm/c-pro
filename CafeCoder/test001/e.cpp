#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    sort(s.begin(), s.end());

    rep(i, n) cout << s[i] << "\n";

    return 0;
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

bool is_p(string s, int l, int r){
    string sub = s.substr(l, r-l+1);
    int n = sub.size();

    rep(i, n){
        if(sub[i] != sub[n-i-1]) return false;
    }

    return true;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();

    if(is_p(s, 0, n-1) && is_p(s, 0, (n-1)/2-1) && is_p(s, (n+3)/2-1, n-1)) puts("Yes");
    else puts("No");


    return 0;
}
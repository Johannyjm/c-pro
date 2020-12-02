#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int ABcount(string s){
    int n = s.size();
    int ret = 0;
    rep(i, n-1){
        if(s[i]=='A' && s[i+1]=='B') ++ret;
    }
    return ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> cnt(n); // 1: front B, 2: back A
    int res = 0;

    rep(i, n){
        string s;
        cin >> s;
        res += ABcount(s);

        if(s.front()=='B') cnt[i] += 1;
        if(s.back() == 'A') cnt[i] += 2;
    }

    int buf1 = 0;
    int buf2 = 0;
    int buf3 = 0;
    rep(i, n){
        if(cnt[i] == 0) continue;
        if(cnt[i] == 1 || cnt[i] == 3) ++buf1;
        if(cnt[i] == 2 || cnt[i] == 3) ++buf2;
        if(cnt[i] == 3) ++buf3;
    }

    res += min(buf1, buf2);
    if(buf1!=0 && buf1==buf2 && buf2==buf3) --res;

    cout << res << endl;

    

    return 0;
}
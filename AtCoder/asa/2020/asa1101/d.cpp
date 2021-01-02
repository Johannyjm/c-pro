#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();

    vector<int> cnt(n, 0);
    int ptr = 0;
    int l = 0;
    while(ptr < n-1){
        if(s[ptr]=='2' && s[ptr+1]=='5'){
            l = 1;
            while(ptr+3 < n && s[ptr+2]=='2' && s[ptr+3]=='5'){
                ptr += 2;
                ++l;
            }
            ++cnt[l];
            ++ptr;
        }
        else ++ptr;
    }

    // rep(i, n) cout << cnt[i] << " ";
    // cout << endl;

    ll res = 0;
    for(ll i = 0; i < n; ++i){
        res += cnt[i]*(i*(i+1)/2);
    }

    cout << res << endl;

    return 0;
}
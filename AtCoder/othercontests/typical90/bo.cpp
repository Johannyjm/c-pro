#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

ll oct2n(string s){
    ll ret = 0;
    ll n = s.size();

    rep(i, n){
        ret += ll(s[i] - '0') * ll(pow(8, n-i-1));
    }
    return ret;
}

string nto9(ll num){
    if(num == 0) return "0";
    string ret = "";
    ll tmp = num;
    while(tmp > 0){
        ret += char('0' + tmp%9);
        tmp /= 9;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

string proc(string s){
    string tmp = nto9((oct2n(s)));
    string ret = "";
    for(char c: tmp){
        if(c == '8') c = '5';
        ret += c;
    }
    return ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string n;
    int k;
    cin >> n >> k;

    string res = n;
    for(int i = 0; i < k; ++i){
        res = proc(res);
    }

    cout << res << endl;

    return 0;
}
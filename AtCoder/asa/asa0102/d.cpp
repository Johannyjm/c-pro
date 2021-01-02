#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

vector<bool> seen;

int str2int(string s){
    int ret = 0;
    int n = s.size();
    rep(i, n){
        ret += (s[i]-'0') * pow(10, n-i-1);
    }

    return ret;
}

string enfilter(string s, string f, int idx){
    if(s.size() != f.size()) return s;

    int n = s.size();
    rep(i, n){
        if(s[i] != f[i] && f[i] != '*'){
            return s;
        }
    }

    string ret = "";
    rep(i, n) ret += "*";
    seen[idx] = true;
    return ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<string> s;
    int n = -1;
    while(1){
        string s_;
        cin >> s_;
        
        int num = s_[0] - '0';
        if(0<=num && num<=9){
            n = str2int(s_);
            break;
        }

        s.push_back(s_);
    }

    int m = s.size();

    vector<string> res = s;
    seen.resize(m, false);
    rep(i, n){
        string f;
        cin >> f;

        rep(j, m){
            if(!seen[j]) res[j] = enfilter(s[j], f, j);
        }
    }

    rep(i, m-1) cout << res[i] << " ";
    cout << res.back() << endl;




    return 0;
}
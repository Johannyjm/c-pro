#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int enhash(string s){
    int ret = 0;
    for(char c: s){
        ret += c - 'a' + 1;
    }
    return ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    if(s=="a" || s=="zzzzzzzzzzzzzzzzzzzz"){
        puts("NO");
        return 0;
    }

    int h = enhash(s);

    string res = "";
    int n = h;
    // --n;
    while(n){
        // cout << n << endl;
        if(n >= 26){
            res += 'z';
            n -= 26;
        }
        else{
            res += 'a'+n-1;
            n = 0;
        }
    }

    if(s == res){
        res = "a";
        int n = h-1;
        // if(n == 0) res += 'a';
        while(n){
            if(n >= 26){
                res += 'z';
                n -= 26;
            }
            else{
                res += 'a'+n-1;
                n = 0;
            }
        }
    }

    // cout << h << " " << enhash(res) << endl;
    if(res.size() > 20){
        res = s;
        swap(res[18], res[19]);
    }

    cout << res << endl;

    return 0;
}
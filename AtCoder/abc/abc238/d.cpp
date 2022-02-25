#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

vector<int> cnv2bin(ll n){
    vector<int> ret(60, 0);
    int ptr = 0;
    while(n){
        ret[ptr] = n%2;
        n /= 2;
        ++ptr;
    }

    return ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while(t--){
        ll a, s;
        cin >> a >> s;

        if(2*a > s){
            puts("No");
            continue;
        }

        vector<int> abin = cnv2bin(a);
        vector<int> sbin = cnv2bin(s);

        bool res = true;
        int d = 0;
        rep(i, 60){
            if(abin[i] == 1){
                if(sbin[i] != d){
                    res = false;
                    break;
                }
                else{
                    d = 1;
                }
            }
            else{
                if(sbin[i] == 1){
                    d = 0;
                }
            }
        }

        if(res) puts("Yes");
        else puts("No");

    }

    return 0;
}
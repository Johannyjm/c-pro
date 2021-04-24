#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int idx[440000];

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    cin >> s;
    int q;
    cin >> q;
    rep(i, 2*n){
        idx[i] = i;
    }

    int isflip = 0;
    rep(_, q){
        int t, a, b;
        cin >> t >> a >> b;
        --a;
        --b;

        if(t == 1){
            if(isflip){
                if(a < n) a += n;
                else a -= n;
                if(b < n) b += n;
                else b -= n;
            }
            swap(idx[a], idx[b]);
        }
        else{
            isflip = 1 - isflip;
        }

        // rep(i, 2*n) cout << idx[i] << " ";
        // cout << endl;
    }


    if(isflip){
        for(int i = n; i < 2*n; ++i) cout << s[idx[i]];
        rep(i, n) cout << s[idx[i]];
    }
    else{
        rep(i, 2*n){
            cout << s[idx[i]];
        }
    }
    cout << endl;

    return 0;
}
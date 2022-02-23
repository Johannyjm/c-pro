#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;
    string s;
    cin >> n >> s >> q;
    vector<char> sl(2*n);
    rep(i, 2*n) sl[i] = s[i];

    bool isflip = false;
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

            swap(sl[a], sl[b]);
        }

        if(t == 2){
            isflip = !isflip;
        }
    }

    if(isflip){
        for(int i = n; i < 2*n; ++i) cout << sl[i];
        rep(i, n) cout << sl[i];
        cout << endl;
    }
    else{
        rep(i, 2*n) cout << sl[i];
        cout << endl;
    }


    return 0;
}
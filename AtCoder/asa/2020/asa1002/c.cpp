#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    if(n == 1){
        int s, prev;
        cin >> s >> prev;
        rep(i, m-1){
            int s, cu;
            cin >> s >> cu;
            if(cu != prev){
                cout << -1 << endl;
                return 0;
            }
            prev = cu;
        }

        cout << prev << endl;
        return 0;
    }

    vector<int> d(n, -1);
    rep(i, m){
        int s, c;
        cin >> s >> c;
        --s;
        if(d[s] != -1 && d[s] != c){
            cout << -1 << endl;
            return 0;
        }
        if(s == 0 && c == 0){
            cout << -1 << endl;
            return 0;
        }
        d[s] = c;
    }

    rep(i, n){
        if(d[i] == -1) cout << 0;
        else cout << d[i];
    }
    cout << endl;

    return 0;
}
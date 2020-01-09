#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int jig, zag;
    cin >> jig >> zag;

    int n_jig = 0;
    int n_zag = 0;
    int n_other = 0;
    int n_buf = 0;
    bool same_flg = false;

    if(jig==zag) {
        ++n_other;
        same_flg = true;
    }

    rep(i, n-2){
        int v;
        cin >> v;

        if(!same_flg){
            if(i%2){
                if(v==zag) ++n_zag;
                else ++n_other;
            }
            else{
                if(v==jig) ++n_jig;
                else ++n_other;
            }
        }
        else{
            if(v == jig) ++n_buf;
            else{
                if(i%2){
                    zag = v;
                    n_other += n_buf/2;
                    same_flg = false;
                }
                else{
                    jig = v;
                    n_other += n_buf/2;
                    same_flg = false;
                }
            }
        }
    }
    if(n_buf) n_other += n_buf/2;

    if(n_other) cout << max(n_other, min(n_jig, n_zag)) << endl;
    else cout << 0 << endl;
}
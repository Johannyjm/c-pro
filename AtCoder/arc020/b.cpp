#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, c;
    cin >> n >> c;

    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
        --a[i];
    }

    int res = 1001001001;
    for(int i = 0; i < 9; ++i){
        for(int j = i+1; j < 10; ++j){
            int ij = 0;
            // ijijij..
            rep(k, n){
                if(k%2==0) {
                    if(a[k] != i) ++ij;
                }
                else{
                    if(a[k] != j) ++ij;
                }
            }

            int ji = 0;
            // jijiji..
            rep(k, n){
                if(k%2==0){
                    if(a[k] != j) ++ji;
                }
                else{
                    if(a[k] != i) ++ ji;
                }
            }

            res = min(res, min(ji, ij));
        }
    }

    cout << res*c << endl;



    return 0;
}
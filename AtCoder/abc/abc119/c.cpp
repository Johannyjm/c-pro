#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, a, b, c;
    cin >> n >> a >> b >> c;
    
    vector<int> l(n);
    rep(i, n) cin >> l[i];

    int res = 1001001001;
    rep1(i, 1<<n){
        rep1(j, 1<<n){
            rep1(k, 1<<n){

                vector<int> use_a(n, 0), use_b(n, 0), use_c(n, 0);
                int cnt_a = 0;
                int cnt_b = 0;
                int cnt_c = 0;
                rep(d, n){
                    if(i & (1<<d)){
                        use_a[d] = 1;
                        ++cnt_a;
                    }
                    if(j & (1<<d)){
                        use_b[d] = 1;
                        ++cnt_b;
                    }
                    if(k & (1<<d)){
                        use_c[d] = 1;
                        ++cnt_c;
                    }
                }

                bool ng = false;
                rep(d, n){
                    if(use_a[d] + use_b[d] + use_c[d] > 1) ng = true;
                }

                if(ng) continue;

                int cost_a = 10 * (cnt_a-1);
                int cost_b = 10 * (cnt_b-1);
                int cost_c = 10 * (cnt_c-1);

                int len_a = 0;
                int len_b = 0;
                int len_c = 0;
                rep(d, n){
                    len_a += l[d] * use_a[d];
                    len_b += l[d] * use_b[d];
                    len_c += l[d] * use_c[d]; 
                }

                res = min(res, abs(a-len_a)+cost_a + abs(b-len_b)+cost_b + abs(c-len_c)+cost_c);
            }
        }
    }

    cout << res << endl;

    return 0;
}
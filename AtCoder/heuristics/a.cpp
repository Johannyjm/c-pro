#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int d;
    cin >> d;

    vector<int> c(26);
    rep(i, 26) cin >> c[i];
    vector<vector<int>> s(d, vector<int>(26));
    rep(i, d) rep(j, 26) cin >> s[i][j];

    vector<int> t(d);
    // rep(i, d){
    //     cin >> t[i];
    //     --t[i];
    // }

    vector<int> last(26, 0);
    vector<pair<int, int>> sms(d);
    int total = 0;
    rep(i, d){
        int res = -1001001001;
        int mxidx = -1;
        rep(tt, 26){
            int sm = 0;
            sm += s[i][tt];
            vector<int> l = last;
            
            int minus = 0;

            rep(j, 26) ++l[j];
            l[tt] = 0;
            rep(j, 26) minus += c[j] * l[j];

            sm -= minus;
            if(sm > res){
                mxidx = tt;
                res = sm;
            }
        }
        rep(j, 26) ++last[j];
        last[mxidx] = 0;
        t[i] = mxidx;
        sms[i] = make_pair(res, i);
        total += res;
    }

    // rep(i, d) cout << t[i] << endl;

    sort(sms.begin(), sms.end());
    
    int res = total;
    rep(didx, d){
        if(didx > 10) break;
        int to = -1;
        rep(kidx, 26){
            vector<int> tt = t;
            tt[sms[didx].second] = kidx;

            vector<int> last(26, 0);
            int res_c = 0;
            rep(i, d){
                res_c += s[i][tt[i]];
                
                int minus = 0;

                rep(j, 26) ++last[j];
                last[tt[i]] = 0;
                rep(j, 26) minus += c[j] * last[j];

                res_c -= minus;
                
            }
            if(res_c > res){
                to = kidx;
                res = res_c;
            }
        }

        if(to != -1){
            t[sms[didx].second] = to;
            sms[didx].first =  res;
        }
    }

    sort(sms.begin(), sms.end());
    
    int res = total;
    rep(didx, d){
        if(didx > 10) break;
        int to = -1;
        rep(kidx, 26){
            vector<int> tt = t;
            tt[sms[didx].second] = kidx;

            vector<int> last(26, 0);
            int res_c = 0;
            rep(i, d){
                res_c += s[i][tt[i]];
                
                int minus = 0;

                rep(j, 26) ++last[j];
                last[tt[i]] = 0;
                rep(j, 26) minus += c[j] * last[j];

                res_c -= minus;
                
            }
            if(res_c > res){
                to = kidx;
                res = res_c;
            }
        }

        if(to != -1){
            t[sms[didx].second] = to;
            sms[didx].first =  res;
        }
    }

    rep(i, d) cout << t[i]+1 << endl;


    return 0;
}
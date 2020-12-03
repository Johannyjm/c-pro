#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();
    int x, y;
    cin >> x >> y;

    vector<int> xs(20000, 0), ys(20000, 0);
    xs[10000] = ys[10000] = 1;

    int isx = 1;
    vector<int> xmove, ymove;
    int cntx = 0;
    int cnty = 0;
    rep(i, n){
        if(s[i] == 'F'){
            if(isx) ++cntx;
            else ++cnty;
        }
        else{
            if(isx){
                if(cntx!=0) xmove.push_back(cntx);
                cntx = 0;
            }
            else{
                if(cnty!=0) ymove.push_back(cnty);
                cnty = 0;
            }
            isx = 1-isx;
        }
    }
    if(cntx!=0) xmove.push_back(cntx);
    if(cnty!=0) ymove.push_back(cnty);

    // for(auto e: xmove) cout << e << " ";
    // cout << endl;
    // for(auto e: ymove) cout << e << " ";
    // cout << endl;

    int st = 0;
    if(s[0] != 'T'){
        xs[10000+xmove[0]] = 1;
        st = 1;
        xs[10000] = 0;
    }
    for(int i = st; i < (int)xmove.size(); ++i){
        vector<int> ixs;
        rep(j, 20000){
            if(xs[j] == 1){
                int l = max(0, j-xmove[i]);
                int r = min(19999, j+xmove[i]);
                ixs.push_back(l);
                ixs.push_back(r);
            }
        }
        xs.assign(20000, 0);
        for(auto idx: ixs) xs[idx] = 1;
    }

    rep(i, (int)ymove.size()){
        vector<int> ixs;
        rep(j, 20000){
            if(ys[j] == 1){
                int l = max(0, j-ymove[i]);
                int r = min(19999, j+ymove[i]);
                ixs.push_back(l);
                ixs.push_back(r);
            }
        }
        ys.assign(20000, 0);
        for(auto idx: ixs) ys[idx] = 1;
    }

    if(xs[10000+x]==1&&ys[10000+y]==1) puts("Yes");
    else puts("No");


    return 0;
}
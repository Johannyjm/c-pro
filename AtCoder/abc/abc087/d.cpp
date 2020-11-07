#include <bits/stdc++.h>
#include <atcoder/all>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
typedef long long ll;


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    dsu uf(n);
    vector<int> pos(n, -1);

    rep(i, m){
        int l, r;
        ll d;
        cin >> l >> r >> d;
        --l;
        --r;

        int pl = pos[l];
        int pr = pos[r];

        if(pl==-1 && pr==-1){
            pos[l] = 0;
            pos[r] = d;

            uf.merge(l, r);
        }

        else if(pl!=-1 && pr!=-1){
            if(uf.same(l, r)){
                if(pos[r] - pos[l] != d){
                    puts("No");
                    return 0;
                }
            }
            else{
                if(pos[r] - pos[l] == d){
                    uf.merge(l, r);
                }
                else{
                    if(uf.size(l) <= uf.size(r)){
                        
                    }
                }
            }
        }
        
    }

    return 0;
}
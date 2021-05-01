#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w, q;
    cin >> h >> w >> q;

    bool colored[2000*2200] = {};
    dsu uf(2000*2200);

    rep(_, q){
        int t;
        cin >> t;
        if(t == 1){
            int r, c;
            cin >> r >> c;
            --r;
            --c;
            int idx = r*w + c;
            colored[idx] = true;
            rep(dir, 4){
                int ny = r + dy[dir];
                int nx = c + dx[dir];
                if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
                int nidx = ny*w + nx;
                if(colored[nidx]){
                    uf.merge(idx, nidx);
                }
            }
        }
        if(t == 2){
            int ra, ca, rb, cb;
            cin >> ra >> ca >> rb >> cb;
            --ra;
            --ca;
            --rb;
            --cb;
            int idx1 = ra*w + ca;
            int idx2 = rb*w + cb;

            if(colored[idx1] && colored[idx2] && uf.same(idx1, idx2)) puts("Yes");
            else puts("No");
        }
    }

    return 0;
}
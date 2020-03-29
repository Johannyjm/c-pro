#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;

    vector<int> p(a);
    vector<int> q(b);
    vector<int> r(c);

    rep(i, a) cin >> p[i];
    rep(i, b) cin >> q[i];
    rep(i, c) cin >> r[i];

    sort(p.begin(), p.end());
    sort(q.begin(), q.end());
    sort(r.begin(), r.end());

    int nx = 0;
    int ny = 0;
    int res = 0;
    while(!(nx==x && ny==y)){
        int pp = p.back();
        int qq = q.back();
        int rr = r.back();

        if(nx==x){
            if(qq >= rr){
                res += qq;
                q.pop_back();
            }
            else{
                res += rr;
                r.pop_back();
            }
            ++ny;
        }

        else if(ny==y){
            if(pp >= rr){
                res += pp;
                p.pop_back();
            }
            else{
                res += rr;
                r.pop_back();
            }
            ++nx;
        }


        else if(max({pp, qq, rr})==pp){
            res += pp;
            p.pop_back();
            ++nx;
        }

        else if(max({pp, qq, rr})==qq){
            res += qq;
            q.pop_back();
            ++ny;
        }

        else if(max({pp, qq, rr})==rr){
            res += rr;
            r.pop_back();

            if(pp <= qq) ++nx;
            else ++ny;
        }
    }

    cout << res << endl;

    return 0;
}
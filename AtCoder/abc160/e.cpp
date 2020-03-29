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

    sort(p.begin(), p.end(), greater<int>());
    sort(q.begin(), q.end(), greater<int>());
    sort(r.begin(), r.end(), greater<int>());

    int res = 0;
    int ptr_p = 0;
    int ptr_q = 0;
    int ptr_r = 0;
    int nx = 0;
    int ny = 0;
    while(!(nx==x && ny==y)){
        if(nx!=x && (ny==y || (p[ptr_p]>q[ptr_q] && p[ptr_p] > r[ptr_r]))){
            res += p[ptr_p];
            ++ptr_p;
            ++nx;
        }
        else if(ny!=y && (nx==x || (q[ptr_q]>p[ptr_p] && q[ptr_q] > r[ptr_r]))){
            res += q[ptr_q];
            ++ptr_q;
            ++ny;
        }
        else if(r[ptr_r]>p[ptr_p] && r[ptr_r] > q[ptr_q]){

            if(ny!=y && (nx==x || p[ptr_p]>=q[ptr_q])){
                res += r[ptr_r];
                ++ptr_r;
                ++ny;
            }
            if(nx!=x && (ny==y || p[ptr_p] < q[ptr_q])){
                ++ptr_r;
                ++nx;
            }
        }
    }
     
    cout << res << endl;

    return 0;
}
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

using mat = vector<vector<ll>>;

mat operator*(mat a, mat b){
    int n = a.size();
    int l = b.size();
    int m = b[0].size();
    
    mat ret(n, vector<ll>(m, 0));

    rep(i, n){
        rep(j, l){
            rep(k, m) ret[i][k] += a[i][j] * b[j][k];
        }
    }

    return ret;
}



int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<mat> points(n);
    rep(i, n){
        ll x, y;
        cin >> x >> y;
        points[i] = mat({{x}, {y}, {1}});
    }

    int m;
    cin >> m;
    vector<mat> mats(m+1);
    mats[0] = mat({
        {1, 0, 0}, 
        {0, 1, 0}, 
        {0, 0, 1}
    });

    rep(i, m){
        int op;
        cin >> op;
        
        if(op == 1){
            mats[i+1] = mat({
                {0, 1, 0}, 
                {-1, 0, 0}, 
                {0, 0, 1}
            }) * mats[i];
        }
        if(op == 2){
            mats[i+1] = mat({
                {0, -1, 0}, 
                {1, 0, 0}, 
                {0, 0, 1}
            }) * mats[i];
        }
        if(op == 3){
            ll p;
            cin >> p;
            mats[i+1] = mat({
                {-1, 0, 2*p}, 
                {0, 1, 0}, 
                {0, 0, 1}
            }) * mats[i];
        }
        if(op == 4){
            ll p;
            cin >> p;
            mats[i+1] = mat({
                {1, 0, 0}, 
                {0, -1, 2*p}, 
                {0, 0, 1}
            }) * mats[i];
        }
    }

    int q;
    cin >> q;
    rep(_, q){
        int a, b;
        cin >> a >> b;
        --b;
        mat res = mats[a] * points[b];
        cout << res[0][0] << " " << res[1][0] << endl;
    }

    return 0;
}
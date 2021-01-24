#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

vector<vector<ll>> prod(vector<vector<ll>> a, vector<vector<ll>> b){
    int n = b.size();
    int m = b[0].size();
    vector<vector<ll>> ret(n, vector<ll>(m));
    
    rep(i, n){
        rep(j, m){
            rep(k, n){
                ret[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return ret;
}


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];

    int m;
    cin >> m;
    vector<vector<vector<ll>>> ops;
    ops.push_back({
        {1, 0, 0}, 
        {0, 1, 0}, 
        {0, 0, 1}
    });

    rep(i, m){
        int op;
        cin >> op;

        if(op == 1 || op == 2){
            if(op == 1){
                ops.push_back(prod(vector<vector<ll>>({
                    {0, 1, 0}, 
                    {-1, 0, 0}, 
                    {0, 0, 1}
                }), ops.back()));
            }
            if(op == 2){
                ops.push_back(prod(vector<vector<ll>>({
                    {0, -1, 0}, 
                    {1, 0, 0}, 
                    {0, 0, 1}
                }), ops.back()));
            }
        }
        else{
            ll p;
            cin >> p;

            if(op == 3){
                ops.push_back(prod(vector<vector<ll>>({
                    {-1, 0, 2*p}, 
                    {0, 1, 0}, 
                    {0, 0, 1}
                }), ops.back()));
            }
            if(op == 4){
                ops.push_back(prod(vector<vector<ll>>({
                    {1, 0, 0}, 
                    {0, -1, 2*p}, 
                    {0, 0, 1}
                }), ops.back()));
            }
        }
    }

    int q;
    cin >> q;
    vector<vector<ll>> res;
    rep(i, q){
        int a, b;
        cin >> a >> b;
        --b;
        res = prod(ops[a], vector<vector<ll>>({{x[b]}, {y[b]}, {1}}));
        cout << res[0][0] << " " << res[1][0] << endl;
    }

    return 0;
}
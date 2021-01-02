#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

bool check(vector<int> a, vector<int> p){
    int n = a.size();
    rep(i, n){
        if(a[i] != p[i]) return false;
    }

    return true;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> p(n), q(n);
    rep(i, n) cin >> p[i];
    rep(i, n) cin >> q[i];

    vector<int> a(n);
    rep(i, n) a[i] = 1+i;

    int cnt = 0;
    int x, y;
    do{
        if(check(a, p)) x = cnt;
        if(check(a, q)) y = cnt;
        ++cnt;
    } while(next_permutation(a.begin(), a.end()));
    
    cout << abs(x-y) << endl;

    return 0;
}
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> p(n), q(n);
    rep(i, n) cin >> p[i];
    rep(i, n) cin >> q[i];

    vector<int> order;
    rep(i, n) order.push_back(i+1);

    int a = -1;
    int b = -1;
    int cnt = 0;
    do{
        if(order == p) a = cnt;
        if(order == q) b = cnt;
        ++cnt;
    } while(next_permutation(order.begin(), order.end()));

    cout << abs(a-b) << endl;

    return 0;
}
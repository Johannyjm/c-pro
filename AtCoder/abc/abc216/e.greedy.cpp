#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    priority_queue<int> pq;
    rep(i, n){
        int a;
        cin >> a;
        pq.push(a);
    }

    ll res = 0;
    while(k--){
        if(pq.empty()) break;
        int val = pq.top();
        // cout << val << endl;
        pq.pop();
        res += val;
        if(val != 0) pq.push(val-1);
    }

    cout << res << endl;

    return 0;
}
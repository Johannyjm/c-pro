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
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    unordered_map<int, int> cnt;
    rep(i, n/2){
        if(a[i] == a[n-i-1]) continue;
        ++cnt[a[i]];
        ++cnt[a[n-i-1]];
    }

    priority_queue<pair<int, int>> pq;
    for(auto k: cnt){
        pq.push({k.second, k.first});
    }

    int res = 0;
    while(!pq.empty()){
        auto [num, val] = pq.top();
        pq.pop();
        if(pq.empty()) break;

        auto [num2, val2] = pq.top();
        pq.pop();

        pq.push({num+num2, val});

        ++res;
    }

    cout << res << endl;

    return 0;
}
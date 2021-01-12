#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(n);
    vector<pair<int, int>> ab(n);
    rep(i, n){
        cin >> a[i] >> b[i];
        ab[i] = {a[i], b[i]};
    }

    sort(ab.begin(), ab.end());

    ab.push_back({-1, 0});
    priority_queue<int> pq;
    int ptr = 0;
    int res = 0;

    rep1(i, m+1){
        if(ab.front().first > i) continue;

        while(ab[ptr].first == i){
            pq.push(ab[ptr].second);
            ++ptr;
        }

        if(!pq.empty()){
            res += pq.top();
            pq.pop();
        }
        
    }

    cout << res << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll N, M, L;
    cin >> N >> M >> L;
    ll A, B, C;
    ll costs[N] = {0};
    ll sum = 0;


    for (int i = 0; i < M; ++i){
        cin >> A >> B >> C;
        sum += C
        costs[B - 1] = sum;
    }

    ll Q;
    cin >> Q;
    ll s, t;

    for(i = 0; i < Q; ++i){
        cin >> s >> t;

        if(costs[s - 1] == 0 or costs[t - 1] == 0){
            cout << -1 << endl;
        }
        else{
            int res = (abs(costs[s - 1] - costs[t - 1])) / L;
            cout << res << endl;
        }
    }
}
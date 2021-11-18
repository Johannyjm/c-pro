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

    vector<string> a(2*n);
    rep(i, 2*n) cin >> a[i];

    vector<int> rank(2*n);
    vector<pair<int, int>> scores(2*n);
    rep(i, 2*n){
        rank[i] = i;
        scores[i] = {0, i};
    }

    auto calc = [&](int p1, int p2, int r){
        char hand1 = a[p1][r];
        char hand2 = a[p2][r];
        if(hand1 == hand2) return -1;
        if(hand1 == 'G'){
            if(hand2 == 'C') return p1;
            return p2;
        }
        if(hand1 == 'C'){
            if(hand2 == 'P') return p1;
            return p2;
        }
        if(hand2 == 'G') return p1;
        return p2;
    };

    rep(i, m){
        rep(k, n){
            int p1 = rank[2*k];
            int p2 = rank[2*k+1];

            int win = calc(p1, p2, i);
            // cout << p1 << " vs " << p2 << ", winner: " << win << endl;
            if(win != -1){
                rep(j, 2*n){
                    if(scores[j].second == win){
                        --scores[j].first;
                        break;
                    }
                }
            }
        }
        sort(scores.begin(), scores.end());
        rep(i, 2*n){
            rank[i] = scores[i].second;
        }

        // for(auto e: scores) cout << e.first << " " << e.second << endl;
        // for(auto e: rank) cout << e << endl;
        // cout << endl;
    }

    rep(i, 2*n) cout << rank[i] + 1 << endl;

    return 0;
}
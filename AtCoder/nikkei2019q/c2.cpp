#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pair<pair<ll, ll>, int>> taka(n), aoki(n);
    for(int i = 0; i < n; ++i){
        ll a, b;
        cin >> a >> b;
        taka[i] = make_pair(make_pair(a, b), i);
        aoki[i] = make_pair(make_pair(b, a), i);
    }

    sort(taka.begin(), taka.end(), greater<pair<pair<ll, ll>, int>>());
    sort(aoki.begin(), aoki.end(), greater<pair<pair<ll, ll>, int>>());

    vector<bool> used(n, false);
    ll score_t = 0;
    ll score_a = 0;
    int idx_t = 0;
    int idx_a = 0;
    bool turn_t = true;
    for(int i = 0; i < n; ++i){
        if(turn_t){
            while(used[taka[idx_t].second]) ++idx_t;
            score_t += taka[idx_t].first.first;
            used[taka[idx_t].second] = true;
        }
        else{
            while(used[aoki[idx_a].second]) ++idx_a;
            score_a += aoki[idx_a].first.first;
            used[aoki[idx_a].second] = true;
        }
        turn_t = !turn_t;
    }
    
    cout << score_t - score_a << endl;

    return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    vector<pair<pair<ll, ll>, int>> t_gr(n), a_gr(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i] >> b[i];
        t_gr[i] = make_pair(make_pair(b[i] - a[i], a[i]), i);
        a_gr[i] = make_pair(make_pair(a[i] - b[i], b[i]), i);
    }

    sort(t_gr.begin(), t_gr.end(), greater<pair<pair<ll, ll>, int>>());
    sort(a_gr.begin(), a_gr.end(), greater<pair<pair<ll, ll>, int>>());
    
    for(int i = 0; i < n; ++i){
        cout << t_gr[i].first.first << " " << t_gr[i].first.second << endl;
    }

    vector<bool> seen(n, false);
    int player = 0; // 0: takahashi, 1: aoki
    int ptr_t = 0;
    int ptr_a = 0;
    ll t_sm = 0;
    ll a_sm = 0;
    for(int i = 0; i < n; ++i){
        if(player == 0){
            while(seen[t_gr[ptr_t].second]) ++ptr_t;
            if(ptr_t == n) break;
            
            t_sm += a[t_gr[ptr_t].second];
            seen[t_gr[ptr_t].second] = true;
            cout << ptr_t << " " << a[t_gr[ptr_t].second] << endl;
        }
        else{
            while(seen[a_gr[ptr_a].second]) ++ptr_a;
            if(ptr_a == n) break;

            a_sm += b[a_gr[ptr_a].second];
            seen[a_gr[ptr_a].second] = true;
            cout << ptr_a << " " << b[a_gr[ptr_a].second] << endl;
        }

        player = 1 - player;

    }
    cout << t_sm << " " << a_sm << endl;
    cout << t_sm - a_sm << endl;


    return 0;
}

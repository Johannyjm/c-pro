#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int rotate(int n){
    ll h = n % 10;
    ll ret = n / 10;

    while(n){
        h *= 10;
        n /= 10;
    }
    h /= 10;

    ret += h;

    return ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll a, n;
    cin >> a >> n;

    queue<ll> q;
    q.push(1);

    const ll INF = 1001001001;
    vector<ll> dist(1100000, INF);
    dist[1] = 0;
    
    while(!q.empty()){
        ll v = q.front();
        q.pop();

        ll nv = -1;
        if(v * a <= 1000000){
            nv = v * a;
            
            if(nv == n){
                cout << dist[v] + 1 << endl;
                return 0;
            }

            if(dist[nv] == INF){
                dist[nv] = dist[v] + 1;

                q.push(nv);
            }
        }

        if(v >= 10 && v % 10 != 0 && v <= 1000000){
            nv = rotate(v);

            if(nv == n){
                cout << dist[v] + 1 << endl;
                return 0;
            }

            if(dist[nv] == INF){
                dist[nv] = dist[v] + 1;

                q.push(nv);
            }
        }
    }

    cout << -1 << endl;

    return 0;
}
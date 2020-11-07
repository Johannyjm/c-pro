#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n;
    m = n-1;
    vector<int> a(n), b(n);
    vector<vector<int>> g(n);
    map<int, int> cnt;
    int hub_size = 0;
    rep(i, m){
        cin >> a[i] >> b[i];
        --a[i];
        --b[i];
        ++cnt[a[i]];
        ++cnt[b[i]];
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);

        hub_size = max({hub_size, cnt[a[i]], cnt[b[i]]});
    }
    cout << hub_size << endl;
    if(hub_size == 2){
        rep(i, m) cout << a[i]%2+1 << endl;
        return 0;
    }

    unordered_set<int> hubs;
    rep(i, n){
        if(cnt[i]==hub_size) hubs.insert(i);
    }

    vector<set<int>> node_color(n);
    vector<int> res(m, -1);
    vector<bool> seen(m, false);
    vector<int> last_color(n, -1);
    
    rep(i, m){
        if(hubs.count(a[i]) && hubs.count(b[i])){
            int color = 1;
            seen[i] = true;

            if(node_color[a[i]].count(color) || node_color[b[i]].count(color)) ++color;
            res[i] = color;
            node_color[a[i]].insert(color);
            node_color[b[i]].insert(color);
            if(color==1){
                last_color[a[i]] = color;
                last_color[b[i]] = color;
            }
        }
    }

    rep(i, m){
        if(seen[i]) continue;
        if(hubs.count(a[i]) || hubs.count(b[i])){
            int color;
            if(hubs.count(a[i])){
                if(last_color[a[i]]==-1) color = 1;
                else color = last_color[a[i]] + 1;
            }
            else{
                if(last_color[b[i]]==-1) color = 1;
                else color = last_color[b[i]] + 1;
            }

            while(node_color[a[i]].count(color) && node_color[b[i]].count(color)) ++color;
            
            res[i] = color;
            if(hubs.count(a[i])) last_color[a[i]] = color;
            else last_color[b[i]] = color;
            seen[i] = true;
            node_color[a[i]].insert(color);
            node_color[b[i]].insert(color);
            
        }
    }

    rep(i, m){
        if(seen[i]) continue;
        int color = 1;
        while(node_color[a[i]].count(color) || node_color[b[i]].count(color)) ++color;

        res[i] = color;
        seen[i] = true;

        node_color[a[i]].insert(color);
        node_color[b[i]].insert(color);
        // cout << res[i] << endl;
    }

    for(auto e: res) cout << e << "\n";



   


    return 0;
}
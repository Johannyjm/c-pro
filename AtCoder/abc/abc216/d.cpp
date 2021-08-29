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
    vector<int> k(m);
    vector<vector<int>> a(m);
    rep(i, m){
        cin >> k[i];
        vector<int> a_(k[i]);
        rep(j, k[i]){
            cin >> a_[j];
        }
        a[i] = a_;
    }

    vector<queue<int>> qs(m);
    rep(i, m){
        queue<int> q;
        rep(j, k[i]){
            q.push(a[i][j]);
        }
        qs[i] = q;
    }

    // rep(i, m){
    //     while(!qs[i].empty()){
    //         cout << qs[i].front() << " ";
    //         qs[i].pop();
    //     }
    //     cout << endl;
    // }
    // return 0;

    unordered_set<int> exsists;
    rep(j, m){
        exsists.insert(j);
    }

    queue<int> popidx;
    // vector<int> cnt(n+1, -1);
    while(1){
        
        bool valid = false;

        // cnt.assign(n+1, -1);
        unordered_map<int, int> cnt;
        for(auto j: exsists){
            if(cnt[qs[j].front()] != 0){
                popidx.push(j);
                popidx.push(cnt[qs[j].front()]-1);
                valid = true;
            }
            cnt[qs[j].front()] = j+1;
        }


        while(!popidx.empty()){
            int idx = popidx.front();
            popidx.pop();

            // cnt[qs[idx].front()] = -1;
            qs[idx].pop();
            if(qs[idx].empty()){
                exsists.erase(idx);
            }
        }

        if(!valid){
            puts("No");
            return 0;
        }

        if(exsists.size() == 0) break;
    }

    puts("Yes");

    return 0;
}
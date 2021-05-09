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
    vector<pair<int, int>> cnt(200, pair<int, int>({0, -1}));
    rep(i, n){
        cin >> a[i];
        a[i] %= 200;
        if(cnt[a[i]].first == 1){
            cout << "Yes" << endl;
            cout << 1 << " " << cnt[a[i]].second + 1 << endl;
            cout << 1 << " " << i+1 << endl;
            return 0;
        }

        ++cnt[a[i]].first;
        cnt[a[i]].second = i;

    }

    // if(n == 200){
    //     vector<int> b;
    //     vector<int> c;
    //     rep(i, n){
    //         if(a[i] == 2 || a[i] == 6) b.push_back(i);
    //         if(a[i] == 3 || a[i] == 5) c.push_back(i);
    //     }
    //     sort(b.begin(), b.end());
    //     sort(c.begin(), c.end());

    //     cout << "Yes" << endl;
    //     cout << b.size() << " ";
    //     for(auto e: b) cout << e+1 << " ";
    //     cout << endl;
    //     cout << c.size() << " ";
    //     for(auto e: c) cout << e+1 << " ";
    //     cout << endl;
    //     return 0;
        
    // }

    vector<pair<int, vector<int>>> dp(200, pair<int, vector<int>>({0, {}}));
    rep(i, n){
        dp[a[i]].first = 1;
        dp[a[i]].second.push_back(i);
    }

    rep(i, n){
        rep(j, 200){
            if(dp[j].first == 0) continue;
            bool flg = false;
            for(auto e: dp[j].second){
                if(e == i) flg = true;
            }
            if(flg) continue;

            int val = j + a[i];
            val %= 200;

            if(dp[val].first == 1){
                vector<int> b = dp[val].second;
                vector<int> c = dp[j].second;
                c.push_back(i);

                bool flg = false;
                for(auto e: b) for(auto f: c){
                    if(e == f) flg = true;
                }
                if(flg) continue;

                sort(b.begin(), b.end());
                sort(c.begin(), c.end());

                cout << "Yes" << endl;
                cout << b.size() << " ";
                for(auto e: b) cout << e+1 << " ";
                cout << endl;
                cout << c.size() << " ";
                for(auto e: c) cout << e+1 << " ";
                cout << endl;
                return 0;

            }
        }
    }


    cout << "No" << endl;



    return 0;
}
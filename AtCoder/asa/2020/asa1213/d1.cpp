#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<pair<char, int>> cnt;
    cnt.push_back({s[0], 1});
    rep1(i, n){
        if(cnt.back().first == s[i]) ++cnt.back().second;
        else cnt.push_back({s[i], 1});
    }

    int m = cnt.size();
    int resg = 0;

    rep(_, 2){
        int res = 0;
        int ctr = 0;
        int l = 0;
        int r = 0;
        rep(i, m){
            if(cnt[i].first == '0') ++ctr;
            if(ctr > k){
                r = i;
                break;
            }
            res += cnt[i].second;
        }

        int prev = res;

        while(1){
            int sm = prev + cnt[r].second;
            if(r+1 < m) sm += cnt[r+1].second;
            sm -= cnt[l].second + cnt[l+1].second;

            res = max(res, sm);
            prev = sm;
            r += 2;
            l += 2;

            if(r >= m) break;
        }

        resg = max(resg, res);

        reverse(cnt.begin(), cnt.end());
    }

    cout << resg << endl;


    return 0;
}
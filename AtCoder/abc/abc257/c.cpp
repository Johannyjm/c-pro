#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    string s;
    cin >> n >> s;
    vector<int> w(n);
    // vector<pair<int, int>> ws(n);
    map<int, pair<int, int>> count;
    rep(i, n){
        cin >> w[i];
        // ws[i] = {w[i], s[i] - '0'};
        if(s[i] == 0) count[w[i]].first++;
        else count[w[i]].second++;
    }

    int res = 0;
    for(auto c: s){
        if(c == '1') ++res;
    }

    int now = res;
    int ptr = 0;
    auto prev = count.begin();
    for(auto k = count.begin(); k != count.end(); ++k){
        if(ptr == 0){
            prev = k;
            ++ptr;
            continue;
        }
        cout << now << " " << prev->second.first << " " << prev->second.second << endl;
        now += prev->second.first;
        now -= prev->second.second;

        cout << now << endl;
        cout << endl;

        res = max(res, now);        

        prev = k;

        ++ptr;
    }

    // sort(ws.begin(), ws.end());

    // int res = 0;
    // int x = ws.front().first;
    // rep(i, n){
    //     if(ws[i].first >= x && ws[i].second == 1) ++res;
    //     if(ws[i].first < x && ws[i].second == 0) ++res;
    // }

    // int now = res;
    // int i = 1;
    // while(i <= n){
    //     while(ws[i].first == ws[i-1].first){
    //         if(ws[i-1].second == 0) ++now;
    //         else --now;
    //         ++i;
    //     }
    //     res = max(res, now);
    //     ++i;
    // }

    cout << res << endl;

    return 0;
}